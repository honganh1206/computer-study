An enterprise usually have many transaction processing systems, and each of them is complex and operates autonomously from each other.

DBAs often do not want business analysts to run queries on OLTP database since those queries are expensive and thus can harm the performance of concurrently executing transactions. Analysts should use data warehouses instead.

A data warehouse contains read-only data of all OLTP systems. Data is extracted (periodic data dumps/streaming) and transformed to analysis-friendly schema, cleaned up, and loaded into data warehouses - ETL.

## Divergence between OLTP databases and data warehouses

The data model is data warehouses is mostly relational, but the internal systems of a data ware house vs. an OLTP database differ since they are optimized for different query patterns.