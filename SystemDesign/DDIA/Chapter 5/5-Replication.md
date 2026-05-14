> [!summary]

**Shared-memory architecture**: Many CPUs, many RAM chips, and many disks can be joined together under one operating system, and a fast interconnect allows any CPU to access any part of the memory or disk.

**Shared-disk architecture**: Several machines with independent CPUs and RAM, but stores data on an array of disks that is shared between the machines, which are connected via a fast network. Mostly for data warehousing workloads, but limited by contention + overhead of locking.

**Shared-Nothing Architecture**: Each machine/VM is called a node, each node uses its CPUs, RAM and disks independently. Any coordination between nodes is done at the software level using a conventional network.

**Replication**: Keep a copy of the same data on several different nodes, providing redundancy

**Partitioning/Sharding**: Split the databases into smaller subsets called *partitions* so that different partitions can be assigned to different nodes.

All the difficulty in replication lies in *handling changes to replicated data*.

[[Leaders and Followers]]