Allow any replica to directly accept writes from clients. Examples are Amazon's Dynamo (used internally), Riak, Cassandra, Voldemort.

In some other cases there is a coordinator node, but it does not enforce a particular ordering of writes.

Scenario: One node goes offline for update. Two nodes accept the writes, and the client ignores the offline replica missed the write.

![[image-5.png]]

When the replica goes online, the client starts reading from it but gets stale data. The client reads from all nodes in parallel, and decides which version to use.

## Read repair and anti-entropy

Read repair: When a client makes a read from several nodes in parallel, it can detect any stale response

Anti-entropy: Some datastores have a background process that looks for differences in the data between replicas. After that, the process copies missing data from one replica to another (This is not done in order like leader-based setup, and there might be delays).

## Quorums (minimum required number of members) for reading and writing

What if only one of three replicas accepts the write? We know that a successful write means it is present on *at least* 2/3 replicas, so only one can have stale data *at most*.  That means we have to query *at least* 2 nodes for updated data.

> If there are $n$ replicas, every write must be confirmed by $w$ nodes to be successful, and we must query at least $r$ nodes for each read. As long as $w + r > n$, we expect to get an up-to-date value when reading.

Read and writes that obey the $w + r > n$ are called **quorum reads and writes**.

![[image-6.png]]

Some scenarios:
- There might not be overlap between $r$ nodes read and $w$ nodes write
- If two writes occur concurrently -> Merge two writes ([[Handling write conflicts]]). If a winner is picked based on a timestamp, writes can be lost due to clock skew (time difference between the clocks of two computer systems)
- Write occurs concurrently with read -> Write reflected on only some replicas
- Write succeeded on fewer than $w$ replicas -> Not rolled back on the replica it succeeded -> Reads may or may not return value from that write

## Monitoring staleness

Leader-based setup: Databases often expose metrics for the replication lag, so we can do: leader's position - follower's position = replication lag.

In a leaderless configuration, there is no limit on how old a value can be, so tracking replication lag is challenging.

## Sloppy Quorums and Hinted Handoff

In a network interruption, fewer than $w$ or $r$ reachable nodes remain, so the cutoff client cannot reach a quorum.

Sloppy quorum: We accept the writes anyway, and write data to reachable nodes even though they are not among the $n$ nodes which the values usually live. -> You lock yourself out of your house and ask your neighbor if you can stay there temporarily.

Hinted handoff: We send the temporarily accepted writes to their appropriate home nodes

[[Detecting concurrent writes]]
