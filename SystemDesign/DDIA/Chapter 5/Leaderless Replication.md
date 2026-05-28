Allow any replica to directly accept writes from clients. Examples are Amazon's Dynamo (used internally), Riak, Cassandra, Voldemort.

In some other cases there is a coordinator node, but it does not enforce a particular ordering of writes.

Scenario: One node goes offline for update. Two nodes accept the writes, and the client ignores the offline replica missed the write.

![[image-5.png]]

When the replica goes online, the client starts reading from it but gets stale data. The client reads from all nodes in parallel, and decides which version to use.

## Read repair and anti-entropy

Read repair: When a client makes a read from several nodes in parallel, it can detect any stale response

Anti-entropy: Some datastores have a background process that looks for differences in the data between replicas. After that, the process copies missing data from one replica to another (This is not done in order like leader-based setup, and there might be delays).

