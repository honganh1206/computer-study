
## Explore Azure Blob storage client library

- A convenient client interface for making calls to Azure Storage

## Create a client object

> [!info] Note
> 
> The following code samples use `DefaultAzureCredential` to authenticate to Azure via Microsoft Entra security principal. The Microsoft Entra security principal requesting the token **must be assigned an appropriate Azure RBAC role** that grants access to blob data.



### Create a `BlobServiceClient` object

- `BlobServiceClient` object allows your app to **interact with resources at the storage account level**.

```csharp
using Azure.Identity;
using Azure.Storage.Blobs;

public BlobServiceClient GetBlobServiceClient(string accountName)
{
    BlobServiceClient client = new(
        new Uri($"https://{accountName}.blob.core.windows.net"),
        new DefaultAzureCredential());

    return client;
}
```


### Create a `BlobContainerClient` object

- `BlobContainerClient` allows interactions with a **specific container resource**

```csharp
public BlobContainerClient GetBlobContainerClient(
    BlobServiceClient blobServiceClient,
    string containerName)
{
    // Create the container client using the service client object
    BlobContainerClient client = blobServiceClient.GetBlobContainerClient(containerName);
    return client;
}

// Create a BlobContainerClient directly without BlobServiceClient

public BlobContainerClient GetBlobContainerClient(
    string accountName,
    string containerName,
    BlobClientOptions clientOptions)
{
    // Append the container name to the end of the URI
    BlobContainerClient client = new(
        new Uri($"https://{accountName}.blob.core.windows.net/{containerName}"),
        new DefaultAzureCredential(),
        clientOptions);

    return client;
}
```


### ## Create a `BlobClient` object

- `BlobClient` allows interactions with a **specific blob resource**

```csharp
public BlobClient GetBlobClient(
    BlobServiceClient blobServiceClient,
    string containerName,
    string blobName)
{
    BlobClient client =
        blobServiceClient.GetBlobContainerClient(containerName).GetBlobClient(blobName);
    return client;
}
```


## Manage container properties and metadata by using .NET

### Retrieve container properties 

To retrieve container properties, call one of the following methods of the `BlobContainerClient` class:

- `GetProperties`
- `GetPropertiesAsync`

### Set and retrieve metadata

To set metadata, add name-value pairs to an `IDictionary` object, and then call one of the following methods of the `BlobContainerClient` class to write the values:

- `SetMetadata`
- `SetMetadataAsync`
