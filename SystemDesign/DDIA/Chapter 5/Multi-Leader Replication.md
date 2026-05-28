We allow one more node to write. The replication process happens in the same way as each node that processes a write must forward that data change to all other nodes.

Certain use cases:

## Multi-datacenter operation

With a normal leader-based replication setup, all writes must go through one datacenter.

In a multi-leader configuration, we have a leader in each datacenter, and within each datacenter, regular leader-follower replication is used. Each datacenter's leader replicates its changes to leaders in other datacenters.

- Performance: Each write must go over the internet, which adds latency. Thus, each write must be processed in the local data center and replicated asynchronously to other datacenters.
- Tolerance of datacenter outages: Multi-leader configuration allows each datacenter to continue operate independently of the others, and replication catches up when the failed datacenter comes back online.
- Tolerance of network problems: Traffic between datacenters goes over public internet, so a multi-leader configuration usually tolerate network problems better since a temporary network interruption does not prevent writes being processed.

Big downside: The same data could be concurrently modified in two different datacenters, and those write conflicts must be resolved.

## Clients with offline operation

There are applications that need to work even though they are disconnected from the internet like calendar apps or Google docs (see meetings as read requests, enter new meetings as write requests, etc.) 

-> Every device has a local database working as a leader, and there is an asynchronous multi-leader replication process between calendar replicas on all your devices.

## Collaborative editing

When one user edits a document, the changes are instantly saved to their local replica, and asynchronously replicated to the server and other users editing the same document.

To guarantee no editing conflicts, the application must obtain a lock on the document before a user can edit it. For faster collaboration, however, we need to make a single unit of change small e.g., a single keystroke and avoid locking.

[[Handling write conflicts]]

[[Multi-Leader Replication Topologies]]