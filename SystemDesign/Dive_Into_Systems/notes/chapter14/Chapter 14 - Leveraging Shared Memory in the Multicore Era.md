 > [!important]
> The terms processors and CPU are used interchangeably. A processor is *any circuit* that performs some computation on external data, while a CPU is an *example* of a processor (Refer to [[Central Processing Unit - CPU]]).

A **core** is a *compute unit* that contains many components that make up the CPU: An ALU, registers and cache.

A processor or a CPU with multiple cores is referred to as a multicore processor or a multicore CPU.

The **Moore's Law** predicts that transistor counts double *every two years*, and this has held true for the past 50 years. However, we have hit several performance walls:

- **Memory wall**: Improvements in memory technology did not keep pace with improvements in clock speed, resulting memory becoming the bottleneck. Today, modern CPUs run at 3–5 GHz (~250 cycles per access), while DRAM access is still on the order of tens of nanoseconds.
- **Power wall**: Increasing the number of transistors of a processor leads to higher power consumption.

Thus, instead of adding more transistors, architects began adding more compute cores, allowing the CPU to execute *multiple independent streams of instructions* at once.

> [!warning] More cores != better
> GPU cores, specialized for particular tasks involving vectors, have fewer transistors than CPU cores. GPUs are more limited in the types of operations they can perform, and computing with GPUs is known as **manycore computing**.

We must identify correctly the number of cores on a system to accurately measure the performance of multicore programs.

> Use the `lscpu` command to inspect the computer's specs.

[[Hyperthreading]]

> [!information]
> On newer architectures like Intel's 12th generation processors, Intel has introduced an architecture that is a mixture of "Performance" cores (P-cores) and "Efficiency" cores (E-cores). This hybrid mixture aims to *delegate* smaller background tasks to the smaller E-cores, while reserving power-hungry P-cores for compute-extensive tasks.

[[Programming Multicore Systems]]

[[POSIX Threads]]

[[Synchronizing Threads]]

[[Measuring the performance of parallel programs]]

[[Caches on Multicore systems]]

But cache coherence can harm performance, thus enters [[False Sharing]]

[[Thread Safety]]

