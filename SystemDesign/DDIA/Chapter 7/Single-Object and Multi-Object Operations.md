## Multi-Object Operations

Multi-object transactions are when we try to modify several objects (rows, documents, records) at once.

Scenario: Store the number of unread emails in a separate column, and increment/decrement the cell when people read/unread the emails.

![[image.png]]

User 2 reads the unread counter before the update to the unread counter is committed (dirty read)

![[image-1.png]]

If the update to the counter fails, atomicity ensures the transaction is aborted and the inserted email is rolled back.

In a TCP connection to a database server, everything between `BEGIN TRANSACTION`  and `COMMIT` is considered part of the same transaction.

## Single-Object Writes

Mostly of document databases? Atomicity can be implemented using a log for crash recovery (refer to WAL in [[B-Trees]]) and isolation can be implemented using a lock on each object.

## When to use what

Cases to use multi-object transactions:
- When inserting a record to a relational database. References (foreign keys) must remain correct and up-to-date
- When updating multiple fields within the same document (document database)
- In databases with second indexes (mostly everything except key-value stores) because the indexes need update when we change the value

Other than that single-object transactions are sufficient.

## Handling errors and aborts

Retrying aborted transactions can have some side effects:
- Transaction succeeds but network failed -> Client fails to acknowledge the  transaction -> Transaction is performed twice
- Overload error -> Limit the number of retries
- Only transient errors (deadlock, isolation violation, temporary network interruptions, failover) are worth retrying, but a permanent error (constraint violation) is not worth retrying

## Preventing lost updates

When two writes happen concurrently, either modification could be lost. To deal with that:
- *Atomic write operations*: Take an exclusive lock on the object, so that no other transaction can read it until the update has been applied. Another approach is to force all atomic operations to execute in a single thread.
- *Explicit locking*: Tell the application to explicitly lock objects that are going to be updated, so the application can perform the read-modify-write cycle.
- *Automatically detecting lost updates*: Allow many read-modify-write cycles to execute in parallel. If the transaction manager detects a lost update, abort the transaction + retry the RMW cycle.
- *Compare and set*: Have a `WHERE` condition to check the content before updating (may not work with snapshots)

## Conflict resolution and replication

Locks and compare-and-set operations work with single up-to-date copy of the data, but with replication we can have several writes happen concurrently, so we cannot guarantee a single up-to-date copy of the data.

[[Detecting concurrent writes]] says we can have multiple conflicting versions of a value, and we use application code/data structure to resolve the conflict.

Atomic operations can work well in a replicated context since that context is commutative, like incrementing a counter (merging all updates together).

Last-write-win (LWW) is the default in many databases, even though it is prone to lost updates.

## Write Skew and Phantoms

Scenario: Designing an application for on-call doctors. At least one doctor must be on call. Alice and Bob both feel unwell, so they press the off-call button at the same time.

![[image-6.png]]

Since the transactions read from the snapshot, both checks return 2, so both transactions proceed to the next stage -> No doctor is on call (Write skew)

Causes: Phantoms causing write skew. If we use `SELECT` to get conditions before writing to the database, rows might be absent and thus we cannot attach locks to it.

Options to resolve:
1. Configure constraints involving multiple objects with triggers/materialized views
2. Explicitly lock the row the transaction depends on

## Materializing conflicts

Cool method: Artificially introduce a lock object into the database

Book-a-meeting-room scenario: Create all possible combinations of rooms and time periods for the next 6 months in a table. When creating a booking, the transaction can acquire the lock for the desired room and time period.

Downside: Error prone to figure out how tow materialize conflicts + ugly code that leaks concurrency control mechanism to application code.