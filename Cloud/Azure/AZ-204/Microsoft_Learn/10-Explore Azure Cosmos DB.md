

> [!info] Definition
> 
> Azure **Cosmos** DB is a **fully managed NoSQL database** designed to provide low latency, elastic scalability of throughput, well-defined semantics for data consistency, and high availability.


| Terms           | Definition                                                                                                         |
| --------------- | ------------------------------------------------------------------------------------------------------------------ |
| throughput      | The measure of the system's capacity to process and handle the workload or operations within a specific time frame |
| schema-agnostic | The container does not enforce or rely on a predefined schema or data structure                                    |


## Identify key benefits of Azure Cosmos DB

- With Azure Cosmos DB, you can **add or remove the regions associated with your account at any time**.
- Azure Cosmos DB offers 99.999% read and write availability for multi-region databases. => Your application **doesn't need to be paused or redeployed to add or remove a region**.


## Explore the resource hierarchy

- The Azure Cosmos DB account is the fundamental unit of global distribution and high availability.

### Elements in Azure Cosmos DB account

- Azure Cosmos DB container == Fundamental unit of scalability 
- Azure Cosmos DB **transparently partitions your container using the logical partition key** that you specify in order to **elastically scale your provisioned throughput and storage**.

![[Pasted image 20240504135808.png]]


> [!info]
> 
> Currently, you can create **a maximum of 50 Azure Cosmos DB accounts** under an Azure subscription

### Azure Cosmos DB databases

- A database is analogous to a namespace 
- A database is the **unit of management** for a set of Azure Cosmos DB containers.

### Azure Cosmos DB containers

- ACDB container = **Unit of scalability** both for provisioned throughput and storage
- A container is **horizontally partitioned** and then **replicated across multiple regions**.
- Two throughput configurations:
	- Dedicated: Throughput reserved for that container + backed by SLAs
	- Shared: The provisioned throughput on the database is shared among all the “shared throughput” containers
- A container is a **schema-agnostic** container of items

### Azure Cosmos DB items

- Depending on the API, Azure Cosmos DB items can be a document/row/node

## Explore consistency levels

- Azure Cosmos DB approaches data consistency as a spectrum of choices instead of two extremes => Provide options to **make precise choices and granular tradeoffs** with respect to high availability and performance

![[Pasted image 20240504142739.png]]

## Choose the right consistency level

 The default consistency level configured on your account:
 - Applies to **all Azure Cosmos DB databases and containers** under that account
 - Can be changed anytime


### Strong consistency

- Offers a **linearizability** (the ability to serve requests concurrently) guarantee. => Users are always guaranteed to read the latest committed write

### Bounded staleness consistency

- The reads **might lag behind** writes by **at most "K" versions** (that is, "updates") of an item or **by "T" time interval**, whichever is reached first.
- Single region: K - 10 write operations/ T - 5 seconds
- Multiple regions: K - 100,000 write operaitons / T - 300 seconds


### Session consistency

- Assumes **a single "writer" session** or **sharing the session token** for multiple writers.

### Consistent prefix consistency

### Eventual consistency


- There's no ordering guarantee for reads => Eventual consistency is the weakest form of consistency because **a client may read the values that are older than the ones it read before**.


## Explore supported APIs

- Some database APIs include:
	- NoSQL
	- MongoDB
	- PostgreSQL
	- Apache Cassandra
	- Table
	- Apache Gremlin

### NoSQL

- Store data in document format => Best E2E experience for full control
- Provide support for querying items using SQL syntax

### MongoDB

- Stores data in a document structure, **via BSON format**

### PostgreSQL

- Managed service for running PostgreSQL at any scale
- Store data either on a single node/distributed in multi-node configuration

### Apache Cassandra

- Store data in column-oriented schema 

### Apache Gremlin

- Store data as edges and vertices

### Table

- Store data in key/value format => Overcome limitations in latency/scaling/throughput/global distribution/index management/low query performance of Azure Table storage 

## Discover request units

- The cost of all database operations is normalized by Azure Cosmos DB and is expressed by _request units_ (RUs) - Representing the system resources (CPU, IOPS, memory, etc.) required to perform the database operation 
	- The cost to do a point read, which is fetching a single item by its ID and partition key value, for a 1-KB item is **1RU**

> [!important]
> 
> No matter which API you use to interact with your Azure Cosmos container, costs are measured by RUs.


![[Pasted image 20240505000212.png]]

- The type of Azure Cosmos DB account you're using determines the way consumed RUs get charged. There are 3 modes:
	- Provisioned: Provision the number of RUs
	- Serverless: No need to provision when creating resources
	- Auto-scale: Automatically + Instantly scale the throughput (RU/s)