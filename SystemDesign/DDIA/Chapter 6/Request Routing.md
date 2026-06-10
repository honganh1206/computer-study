Answer the question: When a client wants to make a request, how does it know which node to connect to? Several approaches to this problem:
1. Allow clients to contact any node via round-robin load balancer
2. Send all requests to a routing tier first as a partition-aware load balancer
3. Clients are made aware of the partitioning and the assignments of partitions to nodes

![[image-5.png]]

Challenge: All participants agree, otherwise requests will be sent to the wrong nodes and handled incorrectly.

Example: ZooKeeper as a separate coordination service. Each node registers itself to ZooKepper, and ZK maintains the *authoritative mapping* of partitions to nodes, which can be used by the routing tier/partitioning-aware clients.

![[image-6.png]]

Databases like Cassandra and Riak use the *gossip protocol*, where one request can be sent to any node, and that node forwards them to appropriate node for the requested partition.

## Parallel Query Execution

*Massive parallel processing* (MPP) relational database products usually several joins, filterings, groupings, etc. in one query.

The MPP optimizer breaks this complex query into a number of execution stages and partitions, which can be executed in parallel on different nodes of the database cluster.