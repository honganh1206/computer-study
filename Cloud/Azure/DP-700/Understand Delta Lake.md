
An open-source storage layer that adds **relational database semantics** to Spark-based data lake processing

Tables in Fabric are Delta tables signified by the Delta (Δ) icon

![[image-10.png]]

Delta tables are just *schema abstractions* over files stored in Delta format

For each table the lakehouse stores a folder containing 

1. Parquet data files 
2. A `_delta_Log` folder with transaction details

![[image-11.png]]


Why Delta Lake?

- Relational databases
- Support for ACID
- Data versioning and time travel
- Standard formats and interoperability

