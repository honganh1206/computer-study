## Dataflow through databases

One process encodes the data, and one process decodes it. There might be several processes accessing the database at the same time.

A value in the database might be written by newer code and read by older code, so forward compatibility is required for databases.

There is also a case when we add a field to a record schema, and the newer code writes a value to that field, but there is older code reads the record then writes it back -> Old code should keep the new field intact.

![[image-4.png]]

*Different values written at different times*: Data outlives code, code constantly changes, while data might stay for many years. Most databases use `null` default value when adding new column to avoid rewriting old data.

*Archival storage*: When dumping data to warehouse, the data will typically encoded using the latest schema. The data dump would mostly be immutable, so Avro and Parquet are good choices for this process.

## Dataflow through Services: REST and RPC

