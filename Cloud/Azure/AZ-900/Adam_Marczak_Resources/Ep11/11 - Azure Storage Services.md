
# Types of data 

![[Pasted image 20230915165916.png]]

- Structured: Often relational
- Semi-structured: Often NoSQL

# Azure Blob Storage

![[Pasted image 20230915170021.png]]

- Designed for storage of **files of any kind/BLOB - Binary Large Object files**
- Three storage tiers: Hot/Cool/Archive

# Azure Queue Storage

![[Pasted image 20230915171055.png]]

- Storage for **small pieces of data**
- Designed for **scalable async processing**

# Azure Table Storage

![[Pasted image 20230915212046.png]]

- Store **semi-structured** data (NoSQL)
	- No need for foreign joins/foreign keys/relationships or strict schema
	- Designed for fast access
- Support many programming interfaces and SDKs

# Azure File Storage

![[Pasted image 20230915212500.png]]

- Storage for files which can be accessed via **shared-drive** protocols (SMB)
- Designed to **extend on-premises file shares** or **implement lift-and-shift scenarios**

# Azure Storage Account

![[Pasted image 20230915213339.png]]

- Group of services including:
	- Blob storage
	- Queue storage
	- Table storage
	- File storage
	- Disk storage
- Used to store
	- Files
	- Messages
	- Semi-structured data
- Highly scalable
- Highly durable (11 nines, up to 16 nines)
- Cheapest per GB storage

# Azure File Storage
- Emulate typical disk and file storage in a shared drive => Provide persistent storage capabilities for a VM