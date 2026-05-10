**Materialized aggregates** cache some of the counts and sums that queries often use, so we don't have to crunch through the raw data every time. We do so using *materialized views*.

Materialized views are actual copies of the query results written to disk, whereas virtual views are just *shortcuts* for writing queries: When we read a virtual view, the SQL engine expands it into the query and process the query.

When the underlying data changes, materialized views must be updated, making writes more expensive and thus not suitable for OLTP databases.

## Data cube/OLAP cube

A grid of aggregates grouped by different dimensions.

![[image-9.png]]

Suppose each fact has foreign keys to *date* and *product*, each one is an axis. Each cell contains an aggregate (SUM) of an attribute (net_price) of all facts.

Data cubes are not flexible as querying raw data.