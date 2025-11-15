**High-performance computing (HPC)** are sophisticated multinode supercomputers to analyze a huge amount of data.

**High-end data analysis (HDA)** systems are used for storage and analysis of large internet-based data.

Both HPC and HDA include a distributed filesystem that allows users and applications common access to files sharedby multiple nodes in the cluster.

![[image-4.png]]

Unlike supercomputers (built and optimized for HPC use), HDA relies on **data centers**, which consist of a large collection of general-purpose compute nodes networked together via Ethernet.

Data centers employ VMs, large distributed databases and frameworks that enable *high throughput analysis of internet data*

[[Cloud computing]]

[[MapReduce]]

[[Fault Tolerance]]

## Opportunities and challenges

Most new data is produced in **edge environments** (near sensors and other data-generating instruments) from IoT devices, and these environments are *on the other end of the network from cloud providers and HPC systems*. This exarcebation of data means we cannot just gather the data and analyze it using a *local* cluster.

To address these logistics issues of "Big Data", the research community is creating techniques that *aggressively summarize data at each transfer point between the edge and the cloud*. This also leads to **edge computing** - analysis occurs at the source of data production (first mile).

Another cross-cutting concern is power management. While local data processing helps mitigate this, the computing infrastructure at those edge environments must use the minimal energy possible.

Other interests: Converge the HPC and cloud computing ecosystems to a common set of frameworks, domain-specific architectures (DSAs) and application-specific integrated circuits (ASICS).