A *replication topology* describes the communication paths for writes to propagate from one node to another. All-to-all is the most popular one.

![[image-3.png]]

To prevent infinite replication loops, each node is given an unique ID, and each write is tagged with the identifiers of all the nodes it has passed through.

The fault tolerance of circular + start topology is not great since if one node fails, all nodes are unable to communicate. The tolerance of all-to-all one is better since it allows travels along different paths.

## Problems with all-to-all

![[image-4.png]]

If leader 1 inserts a row and leader 3 updates the row, leader 2 handling the replication might receive the update sooner than the insertion, so it will update a non-existing row. -> Use *version vectors* to resolve.