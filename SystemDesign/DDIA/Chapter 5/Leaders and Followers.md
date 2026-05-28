To answer the question: How do we ensure all data ends up on all the replicas?

Every write to the database must go through every replica to ensure all replicas contain the same data. For this we do the **leader-based replication**.

1. One replica is designated as the leader. When a client wants to write to the database, they must send their requests to the leader, which will write the new data to the local storage.
2. The other replicas are followers. When the leader writes new data to its local storage, it also sends the data change to all its followers. Each follower updates its local copy in the same order they were processed by the leader.
3. When a client wants to read from the database, it can query either the leader or the followers, but writes are only accepted on the leader.

![[image.png]]

[[Synchronous vs Asynchronous Replication]]
## Setting up new followers

1. Take a snapshot of the leader's database
2. Copy the snapshot to the follower node
3. The follower connects to the leader and requests all the data changes since the snapshot was taken.
4. When the follower catches up with the changes, it continue processing the data.

## Handling node outages

### Follower failure: Catch-up recovery

Each follower keeps a log of data changes received from the leader. If a follower is down and restarted, it can look at the log to see the last transaction before the fault occurred, then reconnects with the leader to request the data changes.

### Leader failure: Failover

We promote a follower to be the new leader:
1. Determine the leader has failed.
2. Choose a new leader through an election process or the new leader could be appointed by a controller node.
3. Followers vote with consensus.

Some case scenarios:
- If the old leader rejoins the cluster after the new leader has been chosen, and there are writes that the old leader failed to replicate to the new leader, what would happen with those writes? We cannot just discard them.
- Two nodes could believe they are the leader (split brain), and if both of them accept writes, there is no process to resolve conflicts.

[[Replication Logs]]
