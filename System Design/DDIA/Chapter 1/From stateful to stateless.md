---
id: From stateful to stateless
aliases:
  - From stateful to stateless
tags: []
---

# From stateful to stateless

Taking stateful data systems from a single node to a distributed setup can _introduce additional complexity_. However, distributed systems will become the default in the future, even for cases that do not handle high-volume traffic

> [!TIP] Scale before going distributed
> Common wisdom is to _keep your database in a single node and scale up_ until scaling cost or high-availability requirements forces you to make it distributed

While there is no one-size-fits-all scalabe architecture, we need to tailor the architecture from the mixture of different ones. These are some factors to take into the equation:

- Volume of reads & writes
- Volume of data storage
- Data complexity
- Response time requirements
- Access patterns
- ...
