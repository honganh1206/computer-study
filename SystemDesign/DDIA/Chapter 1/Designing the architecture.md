---
id: Designing the architecture
aliases:
  - Designing the architecture
tags: []
---

# Designing the architecture

While there is no one-size-fits-all scalabe architecture, we need to tailor the architecture from the mixture of different ones. These are some factors to take into the equation:

- Volume of reads & writes
- Volume of data storage
- Data complexity
- Response time requirements
- Access patterns
- ...

An architecture that scales well for a particular application is built from **assumptions** of which operations will be common and which will be rare

> [!TIP] Advice for startup architecture
> Startups should be able to _iterate quickly on product features_ rather than scale to some hypothetical future load

Even though architectures are specific to different applications, they are still _built from general-purpose building blocks_
