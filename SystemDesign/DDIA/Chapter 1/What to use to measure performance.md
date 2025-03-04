---
id: What to use to measure performance
aliases:
  - What to use to measure performance
tags: []
---

# What to use to measure performance

Usually we use the **average response time** as the _arithmetic mean_ (Given `n` values, add up all the values, and divide by `n`). However, the mean is not really a good metric

It is better to use **percentiles**: Take the response times and sort them from fastest to slowest. The **median** is the _halfway point_

[Percentiles in Practice](01-Areas/Computer/System%20Design/DDIA/Chapter%201/Percentiles%20in%20Practice.md)

This means _half of user requests are served in less than the median response time, and the other half take longer_

The median could also be known as **the 5-th percentile** or _p50_

High percentiles of response times are known as **tail latencies**, and they directly affect users' experience of the service

> [!TIP] Respect the slow requests
> Amazon requires the response time for internal services to be of p99 (optimize 1 out of 1000) to benefit the customers with the slowest requests. Such people have the most data on the accounts, and thus the most valuable customers.

Percentiles are often used in _service level objectives_ (SLOs) and _service level agreements_ (SLAs)

An SLA may state that the service is considered to be up if the median response time is < 200ms and a 99th percentile under 1s. If the response time is longer, it might as well be down
