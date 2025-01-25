---
id: Thinking About Data Systems
aliases: []
tags: []
---

# Thinking About Data Systems

- A data-intensive application is built from standard building blocks like:

  - **Databases**: Store data
  - **Caches**: Remember the result of an expensive operation
  - **Search indexes**: Allow users to search data by keywords/filters
  - **Stream processing**: Send a message to another process to be handled _asynchronously_
  - **Batch processing**: Periodically crunch a large amount of accumulated data

- Despite the variety of technologies, we still need to figure out which tools and which approaches are the **most appropriate** for the task at hand.

- **Modern technologies are optimized to fit in different categories**: Redis can be used as message queues, and Apache Kafka--traditionally works as message queues--can work with database-like durability

- Furthermore, as applications grow with more wide-ranging requirements, a single tool cannot handle all the data processing. To solve this, we **break the work into tasks** and **let each tool handle each task**, with multiple tools stitched together by our code.

![[Figure 1-1.png]]

- You can see from [[Figure 1-1.png]] that you have _created a new, special-purpose data data system from smaller, general-purpose data systems_ and thus _you are a data system engineer too!_
- Questions may arise: How to ensure correct data? How to provide good
  performance with degraded system parts? How to scale to handle more load? These
  all depend much on **the situation**

- Three most important aspects of any software systems:

1. [Reliability](01-Areas/Computer/System%20Design/DDIA/Chapter%201/Reliability.md) ensures the system to work **correctly** in the face of adversity.
2. [Scalability](01-Areas/Computer/System%20Design/DDIA/Chapter%201/Scalability.md) ensures we have _ways to deal with the growth of our systems_.
3. [Maintainability](01-Areas/Computer/System%20Design/DDIA/Chapter%201/Maintainability.md) ensures the people working on the system can maintain its current behaviors and develop new features.
