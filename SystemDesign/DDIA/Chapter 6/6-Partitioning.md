> [!summary]
> - Partitioning: Spread the data and query load evenly across multiple machines. We need to choose a partitioning scheme appropriate to our data, and rebalance the partitions when nodes are added/removed.
> - Two main approaches: **Key range partitioning** (Sorted keys + a partition owns all the key in a specific range), **Hash partitioning** (Apply a hash function to each key, and a partition owns a range of hashes) and hybrid approach.
> - Secondary indexes: Document-partitioned indexes (indexes are stored in the same partition, write impacts one partition but reads are scattered) and Term-partitioned indexes (An index may include records from all partitions, and we update many partitions when writing, but we only need to read from one partition)

When dealing with large datasets or high throughput, we need to break up data into partitions, known as **sharding**.

Each piece of data (record/row/document) belongs exactly to one partition. Different partitions can be placed on different nodes in a shared-nothing architecture, a large dataset can be distributed across different disks, and a query load is distributed across different processors.

[[Partitioning and Replication]]

[[Partitioning and Secondary Indexes]]

[[Rebalancing Partitions]]

[[Request Routing]]