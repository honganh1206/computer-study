Databases try to hide concurrency issues from application developers with *transaction isolation*. However, isolation is not simple because serializable isolation has a performance cost (and databases don't want to pay that).

Even hard-core ACID databases can have concurrency issues and lead to money lost, so we need to understand concurrency problems thoroughly rather than blindly trusting the tools.

## Read Committed

Most basic level of transaction isolation.
1. When reading, we can only see committed data (no dirty reads)
2. When writing, we can only overwrite committed data (no dirty writes)

Read committed uses a separate snapshot for each query.

### Dirty reads & writes

A dirty read is when a transaction can see uncommitted data from another transaction.

![[image-2.png]]

A dirty write is when the earlier write has not yet committed, but the later write overwrites the uncommitted value. We need to *delay the 2nd write* until the 1st write's transaction has committed or aborted.

Databases prevent dirty writes with *row-level locks*: When a transaction wants to modify an object, it must first acquire a lock on that object, and hold the lock until the transaction is committed => However, one long-running write transaction can force many read-only transactions to wait until the long-running transaction is completed.

Another method: Make the reads get the old value before the transaction is committed.

![[image-3.png]]

## Snapshot Isolation and Repeatable Read

![[image-4.png]]

Two accounts each with $500, transfer $100 from one account to another. If we see one account balance at a time before the incoming payment has arrived, it appears that we only have $900 left -> Read skew

Scenarios when this is unacceptable: *Backups* (when reading backups for restoring, the backup may contain both older and newer version of the data), *analytics queries and integrity checks* (return nonsensical result when observing the DB at different points in time)

## Snapshot Isolation

Each action sees all data at the *start* of the transaction, and at a particular point of time

Largely supported by popular DBs.

We use write locks to implement snapshot isolation, but reads do not need locks

> Readers do not block writers and vice versa

*Multi-version concurrency control* (MVCC): The database must keep several different committed versions of an object.

Snapshot Isolation uses the same snapshot *for an entire transaction*.

![[image-5.png]]

`created_by` saves the ID of the transaction that creates it, and `deleted_by` saves the ID of the transaction that deletes it. 

When a payment is targeted for deletion, only the `deleted_by` cell is filled, and at the future point of time when no transaction can access the deleted data, a GC will remove the row.

*An update is internally translated into a delete and a create*. When updating the balance in Account 2 to $400, transaction 13 deletes the $500 record (made by transaction 5) and creates a $400 record.

## Visibility rules for observing a consistent snapshot

When a transaction reads from a database, transaction IDs are used to decide which objects the transaction can see and which are not.

The goal of these rules is to *help the database present a consistent snapshot of the database at one point in time*.
1. At the start of a transaction, the DB makes a list of in-progress (aborted/not-yet-committed) transactions. Any changes those transactions make are ignored.
2. All writes made by aborted/later transactions are ignored.
3. All other writes are visible

(Above example) When transaction 12 reads from Account 2, it still sees the $400 record and not the new $500 record since transaction 12 is not yet committed.

## Indexes with isolating snapshots

To answer the question: How do indexes work with multi-version database?

Some databases like CouchDB use a append-only/copy-on-write variant of the [[B-Trees]] that *creates a copy of each modified page*. 

Parent pages (up to the root page) are copied and updated to point to the new versions of their child pages. Pages unaffected by writes are not copied.

Every write transaction (or batch of transactions) creates a new B-Tree root, and a root is a *consistent snapshot* of the database at a point in time.

> NOTE: Not that expensive though. Only the nodes along the path from the changed leaf up to the root get rewritten

## Repeatable read, serializable and the naming confusion

Snapshot isolation is called *serializable* in Oracle and in PostgreSQL and MySQL it is called repeatable read. The source of confusion is that *the SQL standard does not have a concept of snapshot isolation*.