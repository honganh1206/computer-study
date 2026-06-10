A node may store more than one partition. Each partition's leader is assigned to one node, and its followers are assigned to other nodes.

![[image.png]]

When some partitions have more data or queries than others, we call it *skewed*. In an extreme case, all traffic can go through one partition only (hot spot)

## Partition by Key Range

We assign a continuous range of keys to each partition, like the volumes of a paper encyclopedia. When we know the boundaries, we know which partition contains the key we are looking for.

Since data may not be evenly distributed, the ranges of keys are not necessarily evenly spaced. Thus, to distribute the data evenly, *the partition boundaries need to adapt to the data*.

The partition boundaries can be chosen manually by an administrator, or automatically by the database.

We keep the keys in sorted order ([[SSTables and LSM-Trees]]) and use range scans, treating the key as concatenated index to fetch several related records in one query.

Hotspot scenario: We set the timestamps as keys (IoT sensors writing to the database) so all the writes end up going to the same partition (the one for today) -> Prefix the key with (for example) the sensor's name, then by time.

## Partition by Hash of Key

A good hash function takes skewed data and makes it *uniformly distributed*. A 32-bit hash function takes a string and returns a random number between 0 and $2^{32}- 1$.

The hash function needs to be cryptographically strong: Some databases like Cassandra and MongoDB uses MD5, and Voldemort uses the Fowler-Noll-Vo function.

![[image-1.png]]

Using the hash of the key for partitioning means we lose the ability to do efficient range queries, as adjacent keys are scattered across all the partitions.

> Cassandra achieves a compromise between the two partitioning strategies: A table in Cassandra is declared with a *compound primary key* consisting of several columns. Only the 1st part of the key is hashed to determine the partition, but other columns are used as a concatenated index for sorting data in Cassandra's SSTables.


[[Consistent hashing]]

Example of concatenated index approach: One user on social media sites may post many updates, and if the primary keys are `(user_id, update_timestamp)` then we can retrieve updates of a particular sorted timestamp, and all data of one user is stored on a single partition.

