Software written for data centers must be **fault tolerant**, meaning it must be able to *continue operation in the face of hardware failures*.

[[MapReduce]] was designed with this in mind: When a worker node fails, the boss node redistributes the failed worker's assigned workload to different node. When the boss node fails (low probability), the MapReduce job aborts and must be rerun on a separate node.

Sometimes a worker node fails to respond to the boss node's ping as it is bogged down by tasks, and MapReduce uses the same pinging and work redistribution strategy to resolve this slowness.

## Hadoop and Apache Spark

An open-source implementation of MapReduce by Yahoo. It comes with Hadoop Distributed File System (HDFS - open-source alternative to Google File System) and HBase (modeled after Google's BigTable)

Hadoop has two issues: 1) Challenge to chain multiple MapReduce jobs into a larger workflow and 2) Writing intermediates to HDFS is a bottleneck for smaller jobs (< 1GB). Apache Spark was designed to resolve these issues 100 times faster.