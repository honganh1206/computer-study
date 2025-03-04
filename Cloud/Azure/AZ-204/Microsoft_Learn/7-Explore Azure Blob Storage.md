
## Explore Azure Blob Storage


- Optimized for storing **massive amounts of unstructured data**
- User/client application can access objects in ABS via HTTP/HTTPs
- Objects in ABS are accessible via Azure Storage REST API/Azure PowerShell/Azure CLI/Azure Storage client library

### Types of storage accounts

- Standard/Premium

### Access tiers

- Hot/Cool/Cold/Archive


## Discover Azure Blob storage resource types

Blob storage offers three types of resources:

- The **storage account**.
- A **container** in the storage account
- A **blob** in a container


### Storage accounts

- Provide a **unique namespace in Azure for your data** e.g., `http://mystorageaccount.blob.core.windows.net`
- Every object stored in ABS has an address that includes your unique account name (Account name + ABS endpoint = Base address for ABS objects)

### Containers

- Organize a set of blobs that is in a way similar to a directory in a file system e.g., `https://myaccount.blob.core.windows.net/mycontainer`
- A storage account can include **unlimited** number of containers, and a container can store **unlimited** number of blobs


### Blobs

- Block blobs: 
	- Store text and binary data
	- Made up of blocks of data => Managed individually
	- Store up to 190TBs
- Append blobs: Block blobs optimized for append operation => Logging data from VMs
- Page blobs: Store virtual hard drive (VHD) files and serve as disks for Azure VMs

## Explore Azure Storage security features

- All data is **automatically encrypted** using Storage Service Encryption
- Support Microsoft Entra ID + RBAC
- Secure data in transit between an application and Azure by using Client-Side Encryption/HTTPS/SMB 3.0
- Encrypt OS and data disks using Azure Disk Encryption
- Grant delegated access to data objects in ABS using a **shared access signature**


### Azure Storage encryption for data at rest

- Data in ABS is encrypted/decrypted using one of the strongest ciphers available
- Azure Storage encryption is enabled for **all** new and existing storage accounts and can't be disabled.
- Storage accounts are encrypted regardless of their performance tier (standard or premium) or deployment model (Azure Resource Manager or classic)

## Discover static website hosting in Azure Storage