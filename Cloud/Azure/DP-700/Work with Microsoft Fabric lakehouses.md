When we create a lakehouse, we will have three default data items

![[image-1.png]]

- The lakehouse contains shortcuts, folders, files ,tables
- The semantic model provides an easy data source
- The SQL analytics endpoint provides read-only access to query data

We have different ways to ingest data into our lakehouse

1. Upload files as usual
2. Dataflow Gen2 (See more at [[Ingest data with Microsoft Fabric]])
3. Notebooks with Apache Spark (See more at [[Configure Spark in Microsoft Fabric]])
4. Data Factory pipelines

We use shortcuts to manage access to different storage account or even a different cloud provider (See more at [[Microsoft Fabric OneLake]])

Source data permissions and credentials are all managed by OneLake

Shortcuts can be created in both lakehouses and KQL databases and *appear as a folder in the lake*