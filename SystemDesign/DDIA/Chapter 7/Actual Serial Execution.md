> [!summary]
> - Every transaction must be small and fast, because all it takes is one slow transaction to stall it all.
> - Active dataset should fit in memory.
> - Write throughput must be low enough to be handled on a single CPU core, or else transactions need to be partitioned.
> - Cross-partition transactions are possible but with hard limits.

In the past, we (naively) believe that a database transaction can encompass the entire flow of user activity for example booking a flight ticket. However, *waiting for user input leads to a huge number of concurrent transactions*.

We then go for *an interactive style of transaction*, where requests go back and forth between the application code and the database server.

=> Remove the concurrency entirely. We execute one transaction at a time on a single thread.

Two developments caused this rethink:
- RAM become cheap enough to hold the entire active dataset
- OLTP transactions are usually short and only make up a small number of reads and writes

The application must submit the entire transaction code to the database ahead of time as a **stored procedure**.

Given all required data is in memory, the stored procedure can execute very fast without waiting for network or disk I/O

![[image-7.png]]

The interactive transaction takes 2 network hops, while the stored procedure takes 1 only.

Stored procedures have bad takes:
- They look quite ugly compared to modern general-purpose languages
- Code running in the database is difficult to manage
- A badly written SP can cause much more troubles (performance wise) than badly written application code

## Partitioning

Executing all transactions serially makes concurrency control simpler, but it limits the transaction throughput to a speed of a single CPU core.

VoltDB supports data partitioning to scale to multiple CPUs.

A challenge: If we can partition the dataset in a way that *each transaction only needs to read/write data within a single partition*, then each transaction can have its own transaction processing thread. In that way, each CPU core can have its own partition.

However, with transactions that need to access multiple partitions, the database must coordinate that, and the stored procedure needs to be performed on *lock-step* (strictly sequential and synchronized) across all partitions.