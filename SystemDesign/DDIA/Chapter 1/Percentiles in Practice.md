---
id: Percentiles in Practice
aliases:
  - Percentiles in Practice
tags: []
---

# Percentiles in Practice

Even if you make the calls parallel, the end-user request still need to _wait for the slowest of the parallel calls to complete_

It takes _one slow call_ to make the entire end-user request slow. And if only a small number of backend calls are slow, this will stall multiple backend calls as the number of requests increases. The end result is _a higher propertion of end-user requests are slow_ (**Tail-latency amplification**)

If you want to add response time percentiles to the monitoring dashboards, _you need to efficiently calculate them on an ongoing basis_
