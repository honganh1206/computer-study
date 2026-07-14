Pessimistic concurrency control mechanism: If something might go wrong, it's better to wait until the situation is safe again before doing anything.

> Two-phase locking is NOT two-phase commit

In 2PL, writers can block BOTH other writers and readers.

2PL is implemented by *having a lock on each object in the database*. The lock can either be in shared mode/exclusive mode.

Rules:
1. If a writer wants to read an object, it must acquire a shared lock. But if another transaction already has an exclusive lock on the object, these transactions must wait.
2. If a transaction wants to write to an object, it must acquire the exclusive lock.
3. No two transactions may hold the shared/exclusive lock at the same time.
4. If a transaction first reads then writes to an object, it can upgrade from the shared lock to the exclusive lock,
5. After acquiring the lock, the transaction continues to hold the lock until the end of the transaction (2nd phase, 1st phase is execution).

**Deadlock** is when transaction A is stuck waiting for transaction B to release its lock.

## Performance

Performance of 2PL is not good: The transaction throughput + response time of 2PL are much worse than under weak isolation.

Reasons: Overhead of acquiring locks + reduced concurrency (a write has to wait for another one to finish).

## Predicate locks

If one transaction has searched for existing bookings in a certain time window, other transactions cannot concurrently insert/update another booking for the same room and time range.

A predicate lock belongs to *all objects that match some search conditions*. If transaction A wants to read from/write to objects transaction B is having the lock on, transaction A must wait until transaction B releases the lock.

The lock applies even to objects that have yet exist in the database (phantoms)

## Index-range locks

Simplified approximation of predicate locks.

When a transaction does some searching on bookings (with indexes on `room_id` and `start_time` + `end_time`), the database can attach a shared lock to the index entry. 

-> When another transaction performs CRUD on the same room, it will have to update the same part of the index and thus having to wait for the shared lock.