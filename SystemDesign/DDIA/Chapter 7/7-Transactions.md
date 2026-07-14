> [!summary]
> - Transactions are an **abstraction layer** for applications to pretend concurrency problems + hardware/software faults don't exist.
> - For complex patterns other than simple readings and writings, transactions can hugely reduce the number of error cases.
> - Different kinds of race conditions: **Dirty reads** (one client reads another client's write before the latter is committed), **Dirty writes** (one client overwrites the data another client has written but not yet to commit), **Read skew** (client sees different parts at different points in time), **Lost updates** (two clients concurrently perform read-modify-write cycle), **Write skews** (A transaction reads a false premise for write decision), **Phantom reads** (A client modifies the data that impacts the search result of another client).
> -  Isolation levels: **Read committed** (only read committed data to prevent dirty reads), **Multi-version concurrency control (MVCC)**, **snapshot isolation** and **manual lock** (prevent read skews, lost updates and phantom reads), **Serializable snapshot isolation** (prevent write skews). 
> - Three approaches to implement serializable transactions: **Execute in serial order** (for small, fast transactions), **Two-phase locking** (lock on each object), **Serializable snapshot isolation** (proceed without blocking by aborting transactions if not serializable).


> Better to deal with performance problems due to overusing transactions, rather than coding around the lack of transactions.

A **transaction** is a way to *group several reads and writes together in a logical unit*. Either all the reads and writes succeed (commit) or fail (abort, rollback).

Applications using transactions do not need to worry about partial failure. 

Transactions are created with a purpose: Simplify the programming model for applications accessing the database.

Not every application needs transactions, and there can be advantages to weakening transactional guarantees or abandoning them entirely.

## Concept of a Transaction

Most relational databases support transactions, but many NoSQL databases abandoned transactions entirely, or only support a weaker set of guarantees

[[ACID]]

[[Single-Object and Multi-Object Operations]]

[[Isolation Levels]]

[[Serializability]]