To answer the question: How do we ensure all data ends up on all the replicas?

Every write to the database must go through every replica to ensure all replicas contain the same data. For this we do the **leader-based replication**.

1. One replica is designated as the leader. When a client wants to write to the database, they must send their requests to the leader, which will write the new data to the local storage.
2. The other replicas are followers. When the leader writes new data to its local storage, it also sends the data change to all its followers. Each follower updates its local copy in the same order they were processed by the leader.
3. When a client wants to read from the database, it can query either the leader or the followers, but writes are only accepted on the leader.

![[image.png]]

[[Synchronous vs Asynchronous Replication]]