---
id: Index
aliases: []
tags: []
---

# Index

## Preface

### What will be in this book?

- An application is **data-intensive** if the quantity/complexity/speed of data
  is the bottleneck--as opposed to **compute-intensive** where CPU cycles are
  the bottleneck
- Despite the buzzwords, we engineers must understand various technologies and
  their trade-offs, thus we need to _dig deeper_ into the buzzwords
- This book will look into successful examples of many popular systems that meet
  scalability/reliability/performance requirements every day.
- The goal is to help you **develop a good intuition** for what your system

### Who is this book for?

- Those who love to code and are considering the strengths and weaknesses of
  some tools
- Those who want to dig deep into the systems they are building

### Scope of this book

- There will be no instruction to install the tools as there is online
  documentation
- This book focuses on **discussing principles and trade-offs** fundamental to
  systems
- We look into the **architecture** of data systems and how they are integrated
  into data-intensive applications
- This book leans towards FOSS but we also discuss proprietary software

## Part 1 - Foundations of Data Systems

Fundamental ideas that underpin the design of data-intensive applications

- [[1-Reliable, Scalable, and Maintainable Applications]]
- [[2-Data Models and Query Languages]]
- [[3-Storage and Retrieval]]
- [[4-Encoding and Evolution]]

## Part 2 - Distributed Data

Handle data stored in multiple machines

- [[5-Replication]]
- [[6-Partitioning]]
- [[7-Transactions]]
- [[8-The Trouble with Distributed Systems]]
- [[9-Consistency and Consensus]]

## Part 3 - Derived Data

Discuss systems that derive some datasets from other datasets. If one database
cannot do everything well, applications need to integrate several different
databases, caches, indexes, etc.

- [[10-Batch Processing]]
- [[11-Stream Processing]]
- [[12-The Future of Data Systems]]
