---
id: Describing Performance
aliases: []
tags: []
---

## Describing Performance

Two ways to look at: **When we increase a load parameter and we keep the system resources/performance, how is the performance/system resources affected?**
For batch processing systems, we care about **throughput** i.e., number of records we can process per second (ideally, running time = size of data set / throughput)

For online systems, **response time** is more important

> [!TIP] Latency and response time
> **Latency** and **response time** are not the same. Response time is _what the client sees_, while latency is the _duration_ that a request is waiting to be handled.

For a system handling a variety of requests, _the response time can vary a lot_. Thus, we need to think of response time _not as a single number, but as a distribution of values_ for measurement

The variation of response time could be due to

- Loss of network packet and TCP retransmission
- A garbage collection pause
- A page fault forcing a read from disk
- Mechanical vibrations in the server rack
- ...

[What to use to measure performance](01-Areas/Computer/System%20Design/DDIA/Chapter%201/What%20to%20use%20to%20measure%20performance.md)

[Head-of-line blocking](01-Areas/Computer/System%20Design/DDIA/Chapter%201/Head-of-line%20blocking.md)

> [!TIP]
> When generating load artificially to test the scalability of a system, the load-generating client needs to _keep sending requests independently of the response time_. Not doing so keeps the queues shorter in the test than in reality, thus skweing the measurements
