Over time, we might want to add more CPUs since query throughput increases, or add more disks and RAM as the dataset size increases, or a backup machine to handle the failed machine's work -> We need to move data from one node to another (rebalancing).

We need:
- Fair shares of data between nodes
- Operations continue during rebalancing
- Move necessary data from node to node only

## Strategies for rebalancing

Do NOT hash mod N: With hash partition, when we increase the number of nodes $N$, we might increase the number of time data needs to move between nodes, since we might calculate node index with modulo operator.

*Create more partitions than there are nodes*. When we add a new node, that node can steal some partitions from other nodes, until all partitions are fairly distributed.

![[image-4.png]]

More powerful nodes (nodes on stronger machines) can take a greater share of load.

Some databases don't support partition splitting and stick with a fixed number of partitions for simplicity.

## Dynamic partitioning

When a partition grows to exceed a configured size, it is split into two partitions so half of the data ends up on each side of the split. Conversely, if lots of data is deleted and a partition shrinks below some threshold, it can be merged with an adjacent partition.

When a large partition is split, one of its two halves can be transferred to another node.

## Partitioning proportionally to nodes

The number of partitions per node remained unchanged, but when we increase the number of nodes, the partitions become smaller. When a new node joins the cluster, it randomly chooses a fixed number of existing partitions to split in halves (which could be unfair splits)

## Automatic or Manual Rebalancing

A *gradient* between fully automatic rebalancing and fully manual: Fully automated rebalancing requires less operational work, but it can be unpredictable. Human in the loop is slower but prevents operational surprises.