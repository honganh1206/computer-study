
Pre-requisites:
- **Microsoft.Azure.Cosmos** NuGet package

## Explore Microsoft .NET SDK v3 for Azure Cosmos DB


```csharp
// Database
CosmosClient client = new CosmosClient(endpoint, key); // NOTE: 1 instance of CosmosClient per lifetime of the application as recommended
DatabaseResponse databaseResponse = await client.CreateDatabaseIfNotExistsAsync(databaseId, 10000);
DatabaseResponse readResponse = await database.ReadAsync();
await database.DeleteAsync();


// Container 
ContainerResponse simpleContainer = await database.CreateContainerIfNotExistsAsync( id: containerId, partitionKeyPath: partitionKey, throughput: 400);

Container container = database.GetContainer(containerId);
ContainerProperties containerProperties = await container.ReadContainerAsync();

await database.GetContainer(containerId).DeleteContainerAsync();

// Items
ItemResponse<SalesOrder> response = await container.CreateItemAsync(salesOrder, new PartitionKey(salesOrder.AccountNumber));


string id = "[id]";
string accountNumber = "[partition-key]";
ItemResponse<SalesOrder> response = await container.ReadItemAsync(id, new PartitionKey(accountNumber));


QueryDefinition query = new QueryDefinition(
    "select * from sales s where s.AccountNumber = @AccountInput ")
    .WithParameter("@AccountInput", "Account1");

FeedIterator<SalesOrder> resultSet = container.GetItemQueryIterator<SalesOrder>(
    query,
    requestOptions: new QueryRequestOptions()
    {
        PartitionKey = new PartitionKey("Account1"),
        MaxItemCount = 1
    });
```


## Create stored procedures

- Stored procedures can create/update/read/query/delete items inside an Azure Cosmos container
- Stored procedures are registered **per collection** => Operate on any document/attachment in that collection

```js
var helloWorldStoredProc = {
    id: "helloWorld",
    serverScript: function () {
        var context = getContext(); // Provide access to all operations that can be performed in Azure Cosmos DB
        var response = context.getResponse();

        response.setBody("Hello, World");
    }
}
```

### Create an item using stored procedures

When you create an item by using a stored procedure, the item is inserted into the Azure Cosmos DB container and an ID for the newly created item is returned.


```js
var createDocumentStoredProc = {
    id: "createMyDocument",
    body: function createMyDocument(documentToCreate) {
        var context = getContext();
        var collection = context.getCollection();
        var accepted = collection.createDocument(collection.getSelfLink(),
              documentToCreate,
              function (err, documentCreated) { // Either handle the exception or throw an error inside the callback
                  if (err) throw new Error('Error' + err.message);
                  context.getResponse().setBody(documentCreated.id)
              });
        if (!accepted) return;
    }
}
```


> [!warning] Arrays as input params for stored procedures
> Even if you pass an array of strings as an input, the array is converted to string and sent to the stored procedure. To work around this, you can define a function within your stored procedure to parse the string as an array.


```js
function sample(arr) {
    if (typeof arr === "string") arr = JSON.parse(arr);

    arr.forEach(function(a) {
        // do something here
        console.log(a);
    });
}
```


> [!important]
> 
> All Azure Cosmos DB operations must complete within a limited amount of time. Stored procedures have a limited amount of time to run on the server.


## Triggers


### Pre-triggers

- Azure Cosmos DB supports pretriggers and post-triggers. 
- Pre-triggers are executed before modifying a database item and post-triggers are executed after modifying a database item.

```js
// NOTE: Pretriggers can't have any input parameters. The request object in the trigger is used to manipulate the request message associated with the operation.
function validateToDoItemTimestamp() {
    var context = getContext();
    var request = context.getRequest();

    // item to be created in the current operation
    var itemToCreate = request.getBody();

    // validate properties
    if (!("timestamp" in itemToCreate)) {
        var ts = new Date();
        itemToCreate["timestamp"] = ts.getTime();
    }

    // update the item that will be created
    request.setBody(itemToCreate);
}
```


### Post-triggers

```js
function updateMetadata() {
	var context = getContext();
	var container = context.getCollection();
	var response = context.getResponse();
	
	// item that was created
	var createdItem = response.getBody();
	
	// query for metadata document
	var filterQuery = 'SELECT * FROM root r WHERE r.id = "_metadata"';
	var accept = container.queryDocuments(container.getSelfLink(), filterQuery,
	    updateMetadataCallback);
	if(!accept) throw "Unable to update metadata, abort";
	
	function updateMetadataCallback(err, items, responseOptions) {
	    if(err) throw new Error("Error" + err.message);
	        if(items.length != 1) throw 'Unable to find metadata document';
	
	        var metadataItem = items[0];
	
	        // update metadata
	        metadataItem.createdItems += 1;
	        metadataItem.createdNames += " " + createdItem.id;
	        var accept = container.replaceDocument(metadataItem._self,
	            metadataItem, function(err, itemReplaced) {
	                    if(err) throw "Unable to update metadata, abort";
	            });
	        if(!accept) throw "Unable to update metadata, abort";
	        return;
	    }
}
```



## Explore change feed in Azure Cosmos DB

> [!summary] Definition
> 
> Change feed in Azure Cosmos DB is a **persistent record of changes** to a container in the order they occur.


### How it works

1. Listen to an Azure Cosmos DB container for changes
2. Output the sorted list of documents that were changed in the order they were modified

### Reading Azure Cosmos DB change feed

> [!tip]
> 
> It is recommended to use the push model because you won't need to worry about polling the change feed for future changes, storing state for the last processed change, and other benefits.

- You can work with the Azure Cosmos DB change feed using either a **push model** or a **pull model**.
	- Push: Change feed processor pushes work to a client to process work
	- Pull: Client has to pull the work from the server

### Push model

- Two ways to read: Azure Functions Azure Cosmos DB triggers (uses the change feed processor behind the scene) / Change feed processor library


#### Use Azure Functions

- You can use small Azure Functions to be triggered when there is an event in your Azure Cosmos DB’s container’s change feed

![[Pasted image 20240505145205.png]]


#### Change feed processor

Four main components:

1. The monitored container: Has the data from which the change feed is generated
2. The lease container: Acts as a **state storage** and **coordinate processing the change feed across multiple workers**
3. The compute instance: Hosts the change feed processor to listen for changes
4. The delegate: The code to handle the changes

```cs
/// <summary>
/// Start the Change Feed Processor to listen for changes and process them with the HandleChangesAsync implementation.
/// </summary>
private static async Task<ChangeFeedProcessor> StartChangeFeedProcessorAsync(
    CosmosClient cosmosClient,
    IConfiguration configuration)
{
    string databaseName = configuration["SourceDatabaseName"];
    string sourceContainerName = configuration["SourceContainerName"];
    string leaseContainerName = configuration["LeasesContainerName"];

    Container leaseContainer = cosmosClient.GetContainer(databaseName, leaseContainerName);
    ChangeFeedProcessor changeFeedProcessor = cosmosClient.GetContainer(databaseName, sourceContainerName)
        .GetChangeFeedProcessorBuilder<ToDoItem>(processorName: "changeFeedSample", onChangesDelegate: HandleChangesAsync)
            .WithInstanceName("consoleHost")
            .WithLeaseContainer(leaseContainer)
            .Build();

    Console.WriteLine("Starting Change Feed Processor...");
    await changeFeedProcessor.StartAsync();
    Console.WriteLine("Change Feed Processor started.");
    return changeFeedProcessor;
}

/// <summary>
/// The delegate receives batches of changes as they are generated in the change feed and can process them.
/// </summary>
static async Task HandleChangesAsync(
    ChangeFeedProcessorContext context,
    IReadOnlyCollection<ToDoItem> changes,
    CancellationToken cancellationToken)
{
    Console.WriteLine($"Started handling changes for lease {context.LeaseToken}...");
    Console.WriteLine($"Change Feed request consumed {context.Headers.RequestCharge} RU.");
    // SessionToken if needed to enforce Session consistency on another client instance
    Console.WriteLine($"SessionToken ${context.Headers.Session}");

    // We may want to track any operation's Diagnostics that took longer than some threshold
    if (context.Diagnostics.GetClientElapsedTime() > TimeSpan.FromSeconds(1))
    {
        Console.WriteLine($"Change Feed request took longer than expected. Diagnostics:" + context.Diagnostics.ToString());
    }

    foreach (ToDoItem item in changes)
    {
        Console.WriteLine($"Detected operation for item with id {item.id}, created at {item.creationTime}.");
        // Simulate some asynchronous operation
        await Task.Delay(10);
    }

    Console.WriteLine("Finished handling changes.");
}
```