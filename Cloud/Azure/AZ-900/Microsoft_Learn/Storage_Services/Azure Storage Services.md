# Azure Storage account

A storage account provides **a unique namespace** for your Azure Storage data that's **accessible from anywhere in the world** over HTTP or HTTPS

```ad-note
Azure Storage accounts represent Azure **IaaS** (Infrastructure as a Service) offering

```


- Redundancy options:
	- Locally redundant storage (LRS)
	- Geo-redundant storage (GRS)
	- Read-access geo-redundant storage (RA-GRS)
	- Zone-redundant storage (ZRS)
	- Geo-zone-redundant storage (GZRS)
	- Read-access geo-zone-redundant storage (RA-GZRS)

| Type                        | Supported services                                                                                           | Redundancy Options                   | Usage                                                                                                                                                                                                                                                                      |
| --------------------------- | ------------------------------------------------------------------------------------------------------------ | ------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Standard general-purpose v1 | - Blob Storage (including Data Lake Storage) </br> - Queue Storage </br> - Table Storage - </br> Azure Files | LRS, GRS, RA-GRS, ZRS, GZRS, RA-GZRS | - Standard storage account type for blobs, file shares, queues, and tables. </br> - Recommended for **most scenarios** using Azure Storage. </br> - If you want support for network file system (NFS) in Azure Files, use the premium file shares account type.            |
| Premium block blobs         | Blob Storage (including Data Lake Storage)                                                                   | LRS, ZRS                             | - Premium storage account type for block blobs and append blobs </br> - Recommended for scenarios with **high transaction rates** or that **use smaller objects** or **require consistently low storage latency**.                                                         |
| Premium file shares         | Azure Files                                                                                                  | LRS, ZRS                             | - Premium storage account type **for file shares only**. </br> - Recommended **for enterprise or high-performance scale applications**. </br> - Use this account type if you want a storage account that **supports both Server Message Block (SMB) and NFS file shares**. |
| Premium page blobs          | Page blobs only                                                                                              | LRS                                  | Premium storage account type for page blobs only                                                                                                                                                                                                                           |


## Storage account endpoints

- Azure Storage Account offers unique namespace for your data
- Rules when naming storage account
	- Mus have 3-24 characters in length
	- Unique within azure

![[Pasted image 20230722112137.png]]

## Steps to store data in Azure storage

1. Create an Azure Storage account
2. Create an Azure Storage container to store data
3. Upload the data


---
# Azure Storage Redundancy

- Azure Storage **always** stores multiple copies of your data in cases of emergency
- Redundancy ensures that your storage account meets its availability and durability in the face of failures

```ad-note
title: Deciding the right redundancy option
When deciding which redundancy option is best for your scenario, **consider the tradeoffs between lower costs and higher availability**. These are factors worth consideration:
- How your data is replicated in the primary region
- Whether your data is replicated to a second region that is *geographically distant* to the primary region, to protect against regional disasters.
- Whether your application *requires read access to the replicated data in the secondary region* if the primary region becomes unavailable

```

## Redundancy in the primary region

### Locally redundant storage

- Advantages
	- Replicates your data **three times** within a single data center **in the primary region**, with **11 nines of durability** (99.999999999%)  
	- Protect your data against server rack and drive failures
- Downsides: Data **might be lost/unrecoverable** if a disaster such as fire or flooding occurs

![[Pasted image 20230722214926.png]]

### Zone-redundant storage

- Advantages
	- Replicate your Azure Storage data **synchronously** across **three Azure availability zones/datacenters in the primary region**  
	- Offers durability for Azure Storage data objects of at least **12 nines (99.9999999999%)** over a given year.  
	- Data is **still accessible for BOTH READ AND WRITE operations** even if a zone becomes unavailable

 ![[Pasted image 20230722220709.png]]

## Redundancy in a secondary region

- We can additionally copy the data in our storage account to a secondary region hundreds of miles away from the primary region => Durable data in the event of catastrophic failure
- The paired secondary region is based on **Azure Region Pairs** and **cannot be changed**
- Two options to **copy data to a secondary region**
	- Geo-redundant storage (GRS) (Updated version of LRS)
	- Geo-zone-redundant storage (GZRS) - (Updated version of ZRS)
- By default, **the secondary region is not available for read or write access unless there is a failover to the secondary region**
- If the failover has happened (and completed), **the secondary region becomes the primary region instead**

```ad-important
- As the data is replicated from the primary region to the secondary region **asynchronously**, a failure that affects the primary region may **result in data loss if the primary region cannot be recovered**
- The interval between **the most recent writes** to the primary/1st region and **the last write** to the secondary/2nd region is known as **Recovery Point Objective (RPO)**, indicating **the point in time to which data can be recovered**
- Azure Storage has an RPO of less than 15 minutes
- Data in your secondary region **may not be up-to-date** due to RPO.
```


### Geo-redundant storage (GRS)

![[Pasted image 20230726211251.png]]

- Data is replicated **3 times** in the primary region (LRS) before being copied **asynchronously** to the 2nd region/the region pair using LRS
- Offer 16 nines (99.99999999999999%) over a given year

### Geo-zone-redundant storage

- Data in GZRS account is copied **across three Azure availability zones in the primary region** (ZRS) and is also replicated to the secondary region using LRS
- Offer 16 nines (99.99999999999999%) over a given year

![[Pasted image 20230726211707.png]]


## Supported Azure Storage services

![[Pasted image 20231022215422.png]]

--- 
# Azure Storage Platform

|               | Definition                                                                                                                                                                                                                                                                                                                                                                    | Usage/Advantages                                                                                                                                                                                                                                                                                         |
| ------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Azure Blobs (Binary Large Object) - The most **general purpose** file storage in Azure  | - A massively scalable object store for **text and binary data** </br> - Unstructured => No restrictions for any kinds of data </br> - Manage **thousands of simultaneous uploads** and available everywhere                                                                                                                                                                  | - Serve images/documents directly to a browser </br> - Store files for distributed access </br> - Stream videos/audios </br> - Store data for backup and recovery </br> - Store data for analysis by an on-premises/Azure-hosted service </br> - Suited for storing disaster recovery files and archives |
| Azure Files   | - Manage file shares in the cloud that are accessible via Server Message Block (SMB) or Network File System (NFS) </br> - While SMB azure file shares are accessible from Windows, Linux and MacOS clients, NSF file shares are only accessible from Linux and MacOS clients </br> - SMB Azure file sync can be cached on Window Servers with Azure File Sync for fast access | - Shared access </br> - Fully managed </br> - Scripting and tooling </br> - Resiliency </br> - Familiar programmability </br> - Mapping network drive for computers                                                                                                                                                                                  |
| Queue storage | - A service for storing **a large numbers of messages** </br> - Can be combined with Azure Functions                                                                                                                                                                                                                                                                          | - Messages can be accessed from everywhere in the world using HTTP/HTTPS </br> - Used to create **a backlog of work**                                                                                                                                                                                    |
| Disk storage  | - Block-level storage volumes by Azure for use with Azure VMs </br> - Virtualized physical disks in essence => Offer great resiliency and availability                                                                                                                                                                                                                        |                                                                                                                                                                                                                                                                                                          |
|               |                                                                                                                                                                                                                                                                                                                                                                               |                                                                                                                                                                                                                                                                                                          |

![[Pasted image 20230726215107.png]]
## Managed Disks

- Handle Azure storage account creation and management in the background
## [More on Azure Blobs - Access tiers](https://learn.microsoft.com/en-us/azure/storage/blobs/access-tiers-overview)

Azure Storage offers different access tiers for blob storage
- Hot access tier: Data that is **accessed frequently** (Images for your website)
- Cool access tier: Data **infrequently accessed** and **stored for at least 30 days** (invoices for your customers) => Short-term data backup and disaster recovery
- Archive access tier: Data rarely accessed and stored for at least 180 days (long-term backups)

![[Pasted image 20230726215130.png]]

```ad-important
title: Considerations for different access tiers
- Only the hot and cool access tiers can be set at the account level
- Hot, cool, and archive tiers can be set at the blob level, during or after upload.
- Data in the cool access tier can tolerate **slightly lower availability**

```

```ad-warning
title: Access tiers for blob data
- While a blob is in the archive tier, it can't be read or modified. To read or download a blob in the archive tier, **you must first rehydrate it to an online tier, either hot, cool, or cold**.
- Only storage accounts that are configured for **LRS, GRS, or RA-GRS** support **moving blobs to the archive tier**.
- Data in the cold tier must be stored for **at least 90 days** before it can be moved to the archive tier

```


---
# Azure data migration options

## Azure Migrate

- Use: Migrate our data from an on-premises environment to the cloud
- Offers:
	- **Unified migration platform** through a single portal
	- **Range of tools** e.g. Azure Migrate: Discovery and assessment, Azure Migrate: Server Migration
	- **Integration** with other Azure services and tools
	- **Assessment and migration**: Assess + migrate our on-premises infra to Azure

## Azure Data Box

- Azure Data Box helps **transfer large amounts of data** by **shipping us a proprietary Data Box storage device of maximum usable storage capacity as 80 terabytes** 
- Each Data Box appliance can move data into up to 10 storage accounts
### Use cases

| Importing data                                                                                                                                                                                                                                                 | Exporting Data                                                                                                                                                                           |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| - One-time migration </br> - Moving a media library from offline tapes to create an online media library </br> - Migrate VM farm, SQL server, applications </br> - Move historical data using HDInsight </br> - Initial bulk transfer </br> - Periodic uploads | - Disaster recovery </br> - Security requirements (Ship data out of Azure due to security/government requirements) </br> - Migrate back to on-premises or another cloud service provider |
|                                                                                                                                                                                                                                                                |                                                                                                                                                                                          |


---
# File management options

![[Pasted image 20230802211413.png]]

---
# Database Services

## Azure Cosmos DB
### Benefits
- Provides a **distributed database service** with support for multiple APIs, including SQL, NoSQL, and graph databases.
- Offers global distribution, automatic scaling, and low latency access.
### Usage
- In order to use Azure Cosmos DB, you need to first create an Azure Cosmos account, and then continue and add databases, containers and items under it. => Not Serverless

## Azure SQL Managed Instance
- Fully fledged SQL server with all capabilities + Minimize management requirements

## Azure Table Storage
- Semi-structured NoSQL database service in Azure alongside with Azure Cosmos DB

---
# [Storage queues & Service Bus](https://learn.microsoft.com/en-us/azure/service-bus-messaging/service-bus-azure-and-service-bus-queues-compared-contrasted)
### Storage queues

- Characteristics:
	- Support FIFO (First-In, First-Out) ordered delivery of messages
	- Support for arbitrary metadata
- Consider to use Storage queues when:
	- Your application must store **over 80 gigabytes of message**s in a queue.
	- Your application wants to **track progress for processing a message in the queue**. It's useful if the worker processing a message crashes. Another worker can then use that information to continue from where the prior worker left off.
	- You **require server side logs of all of the transactions executed** against your queues.

### Service Bus

- Features
	- Scheduled delivery
	- Automatic dead lettering
	- Atomic operations
- Characteristics:
	- Support for **guaranteed first-in-first-out** (FIFO) ordered delivery
	- Support for **automatic duplicate detection**
	- Support for **long-running parallel** messaging processing

---
# [ Azure NetApp Files](https://learn.microsoft.com/en-us/azure/azure-netapp-files/azure-netapp-files-introduction)

- An **enterprise-grade NAS service** that can handle **high-performance, low-latency workloads**.

---
# [Azure File Sync](https://learn.microsoft.com/en-us/azure/storage/file-sync/file-sync-introduction)

- Enables **centralizing your organization's file shares in Azure Files**, while keeping the flexibility, performance, and compatibility of a Windows file server.
- Can be used to **cache the contents of Azure file shares on servers running Windows Server on-premises**.
- Can be used to **configure cloud tiering** so *the most frequently accessed files are replicated locally* and *the infrequent accessed files are kept in the cloud*

```ad-info
Refer to [Migrate from NAS via Data Box to Azure File Sync](https://learn.microsoft.com/en-us/azure/storage/files/storage-files-migration-nas-hybrid-databox) or find the best guide for your scenario on the [migration overview](https://learn.microsoft.com/en-us/azure/storage/files/storage-files-migration-overview) page if you have data on a source where you cannot install Azure File Sync

```

- [A single Windows Server instance (or cluster) can sync up to 30 Azure file shares.](https://learn.microsoft.com/en-us/azure/storage/file-sync/file-sync-planning)
- 

```ad-success
title: Tips
It is recommended to **deploy storage accounts with one file share each** to optimize performance for highly active shares.

```

```ad-important
Before configuring Azure File Sync, the Azure File Sync agent needs to be installed on the on-premises Windows Server instance, as it is **responsible for establishing the connection between the on-premises server and Azure file shares**, allowing for synchronization and management of files between the two environments.

```

---
# [Azure Storage Explorer](https://azure.microsoft.com/en-us/products/storage/storage-explorer)

 - A tool for **managing** and **interacting** with **Azure storage resources**