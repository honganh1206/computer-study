## Statement-based replication

The leader logs every write request/statement that it executes and sends that statement log to its followers. Each follower parses and executes that SQL statement.

Problems with this:

- Statements that use `NOW()` or `RAND()` will generate a different value on each replica
- Statements with auto-incrementing column or they depend on data with `UPDATE...WHERE` then they must be executed in exactly the same order on each replica
- Statements that have side effects like triggers, stored procedures, etc. may result in different side effects on each replica


## Write-ahead Log (WAL) shipping

[[SSTables and LSM-Trees]]

the leader uses an append-only log and sends it across the network to its followers.

A WAL contains details of which bytes were changed in which disk blocks, making replication coupled with the storage engine -> Challenging if the database changes its storage format.

## Logical (row-based) replication

We use different log formats for replication, decoupling the replication log from the storage engine.

A logical log is a *sequence of records* describing writes to the database tables:
- If insert -> Contain all new values
- If delete -> Contain just enough information for identification, usually the primary key
- If update -> Primary key and new values of columns that change

## Trigger-based replication

We move replication up to the application layer for special cases like replicating only a subset of data, replicate from one kind of database to another, etc.

How this works: A trigger lets you register custom application code that automatically executes when there is a data change (write requests) -> Log this change to a separate table read by external process -> External processes replicate data