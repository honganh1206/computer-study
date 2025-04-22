1. A team wants to reuse a pipeline to load data into different lakehouse folders dynamically. Which pipeline feature should they use? - Parameter
2. What are the two broad categories of activities in a pipeline? - Data transformation activities and Control flow activities
3. What is the primary purpose of Activator in Microsoft Fabric's Real-Time Intelligence? - Trigger alerts on streaming data thresholds
4. Which architecture combines batch data loading with real-time data ingestion? - Lambda architecture
5. What does the 'take' operator do in a KQL query? - Retrieves a specified number of rows from a table
6. Which KQL query correctly retrieves events ingested into the Automotive table within the past hour when the data lacks a timestamp? - `Automotive | where ingestion_time() > ago(1h)`
7. Which window type groups events based on a gap of inactivity? - Session
8. Which scenario best justifies using a materialized view instead of a stored function? - Automatically maintaining a pre-aggregated dataset for frequent queries
9. What is the primary purpose of using Dataflows Gen2 in Microsoft Fabric? - Data transformation
10. How does a materialized view populate itself when created without the backfill option? - The view is populated incrementally as new data is ingested
11. What is the primary purpose of the Derived Stream destination in Microsoft Fabric Eventstreams? - To represent the altered default stream after applying stream operations
12. When should you consider using a Data Flow activity instead of a Copy Data activity? - When applying transformations during ingestion
13. In a scenario where you need to process sensor readings that arrive in batches with identical timestamps but from different locations, which windowing function would be MOST efficient? - Snapshot windows with `System.Timestamp()` in the `GROUP BY` clause
14. Which Microsoft Fabric component is specifically designed for ingesting continuous real-time data? - Eventstream
15. What keyword should you use to retrieve only specific columns in a KQL query? - `project`
16. What is the correct KQL syntax to calculate the average of a column named 'price' grouped by 'category'? - `stock | summarize avg(price) by category`
17. Which transformation in Eventstreams is used to combine data from two streams based on a matching condition between them? - `Join`
18. What is a KQL database? - A real-time optimized data store that hosts tables and functions
19. What tool is used to define transformation steps for a Data Flow activity? - Power Query
20. What is the primary use of the Copy Data activity in a data pipeline? - To ingest data from an external source into a lakehouse file or table