
## Explore Azure Functions development

- A **function** contains two important pieces:
	1. Your code
	2. The `function.json` file - The config file

- The `function.json` file defines the function's trigger, bindings, and other configuration settings.

> [!warning]
> 
> Every function has **one and only one trigger**

- The runtime uses this config file to **determine the events to monitor + how to pass data + return a data from a function execution**

```json
{
    "disabled":false,
    "bindings":[
        // ... bindings here
        {
            "type": "bindingType", // Name of binding
            "direction": "in", // Indicate whether the binding is receiving data into the function or sending data from the function
            "name": "myParamName", // The name that is used for the bound data in the function
            // ... more depending on binding
        }
    ]
}
```


### Function app

- Provide an execution context in Azure in which your functions run  => A way to **organize and collectively manage your functions**
- Work as the **unit of deployment and management** for your functions

> [!info]
> 
> All of the functions in a function app share the same pricing plan, deployment method, and runtime version.


### Folder structure / Functions class in library project

In Visual Studio, the **Azure Functions** project template creates a C# class library project that contains the following files:

- [host.json](https://learn.microsoft.com/en-us/azure/azure-functions/functions-host-json) - stores configuration settings that affect all functions in the project when running locally or in Azure.
- [local.settings.json](https://learn.microsoft.com/en-us/azure/azure-functions/functions-develop-local#local-settings-file) - stores app settings and connection strings that are used when running locally. This file contains secrets and isn't published to your function app in Azure. Instead, [add app settings to your function app](https://learn.microsoft.com/en-us/azure/azure-functions/functions-develop-vs#function-app-settings).

```
<framework.version>
 | - bin
 | - MyFirstFunction
 | | - function.json
 | - MySecondFunction
 | | - function.json
 | - host.json
```


### Local development environments

- Your local functions can connect to live Azure services + You can debug them on your local computer using the full Functions runtime => See [Code and test Azure Functions locally](https://learn.microsoft.com/en-us/azure/azure-functions/functions-develop-local)

## Create triggers and bindings

- Binding to a function is a way of **declaratively connecting another resource to the function**
- Triggers and bindings let you avoid hardcoding access to other services.

> [!warning]
> 
> A trigger is **REQUIRED** for a function to run, while the bindings might be optional

> [!tip] Triggers for dynamically typed languages
> 
> For languages that are dynamically typed such as JavaScript, use the `dataType` property in the _function.json_ file.

```json
{
    "dataType": "binary", // Specify the type explicitly
    "type": "httpTrigger",
    "name": "req",
    "direction": "in"
}
```


### Azure Functions trigger and binding example

- Scenario: Write a new row to Azure Table storage whenever a new message appears in the Azure Queue storage => Azure Queue storage trigger + Azure Table storage output binding

```json
{
  "bindings": [
    {
      "type": "queueTrigger",
      "direction": "in",
      "name": "order", // Identify the function param that receives the queue message content
      "queueName": "myqueue-items",
      "connection": "MY_STORAGE_ACCT_APP_SETTING"
    },
    {
      "type": "table",
      "direction": "out",
      "name": "$return",
      "tableName": "outTable",
      "connection": "MY_TABLE_STORAGE_ACCT_APP_SETTING"
    }
  ]
}
```

```csharp
// C# script example

#r "Newtonsoft.Json"

using Microsoft.Extensions.Logging;
using Newtonsoft.Json.Linq;

// From an incoming queue message that is a JSON object, add fields and write to Table storage
// The method return value creates a new row in Table Storage
public static Person Run(JObject order, ILogger log)
{
    return new Person() { 
            PartitionKey = "Orders", 
            RowKey = Guid.NewGuid().ToString(),  
            Name = order["Name"].ToString(),
            MobileNumber = order["MobileNumber"].ToString() };  
}

public class Person
{
    public string PartitionKey { get; set; }
    public string RowKey { get; set; }
    public string Name { get; set; }
    public string MobileNumber { get; set; }
}

// Class library example

public static class QueueTriggerTableOutput
{
    [FunctionName("QueueTriggerTableOutput")]
    [return: Table("outTable", Connection = "MY_TABLE_STORAGE_ACCT_APP_SETTING")]
    public static Person Run(
        [QueueTrigger("myqueue-items", Connection = "MY_STORAGE_ACCT_APP_SETTING")]JObject order,
        ILogger log)
    {
        return new Person() {
                PartitionKey = "Orders",
                RowKey = Guid.NewGuid().ToString(),
                Name = order["Name"].ToString(),
                MobileNumber = order["MobileNumber"].ToString() };
    }
}

public class Person
{
    public string PartitionKey { get; set; }
    public string RowKey { get; set; }
    public string Name { get; set; }
    public string MobileNumber { get; set; }
}

```

## Connect functions to Azure Services

- Your function project references connection information by name from its **configuration provider**.
- The function project does NOT directly accept the connection details => Allow them to be changed across environments


### Configure an identity-based connection

- Some connections in Azure Functions are configured to use an identity instead of a secret + Support depends on the extension using the connection.
- When hosted in the Azure Functions service, identity-based connections use a [managed identity](https://learn.microsoft.com/en-us/azure/app-service/overview-managed-identity?toc=/azure/azure-functions/toc.json). The system-assigned identity is used **by default**, although a user-assigned identity can be specified with the `credential` and `clientID` properties.

### Grant permission to the identity

- Whatever identity is being used must have permissions to perform the intended actions => Azure RBAC