An *optimistic* concurrency control technique. Instead of waiting for awful things to pass (pessimistic), transactions continue anyway, in the hope that everything will turn out right.

When a transaction tries to commit, the database checks for something bad e.g., isolation was isolated, and aborts the transaction. The transaction has to be retried.

Given spare capacity + contention between transactions is not too high, optimistic concurrency control performs better than the pessimistic version.

SSI is based on [[Serializable Snapshot Isolation]], plus an algorithm for detecting serialization conflicts among writes and determine which transactions to abort.

One transaction does not need to block to wait for locks held by another transaction.

## Decisions based on outdated premises 

Premises == Facts that were true at the beginning of the transaction

The database needs to assume that *any change in the premises (read query result) may make the writes invalid*. Thus, the database must detect situations when a transaction may have acted on outdated premises:
- Detect reads of a stale MVCC object version
- Detect writes that affect previous reads

### Detect reads of a stale MVCC object version

![[image-8.png]]

Transaction 43 still sees `on_call = true`, but when t43 tries to commit, t42 has already committed with `on_call = false`, so the premise is wrong.

The database tracks when a transaction (t43) ignores another transaction (t42)'s writes due to MVCC visibility rules. When t43 want to commit, the database manager checks for writes ignored by t43, and if there are, the transaction (t43) is aborted.

## Detect writes that affect previous reads

Check when another transaction modifies the data that has been read.

![[image-9.png]]

We use index-range locks in [[Two-phase Locking]] to lock access to all rows matching some search queries. The database uses the index entry to keep track of transactions that have read this data.

When a transaction writes to the database, it must look in the indexes for any other transactions that recently read the affected data. The write lock does NOT block until readers from other transactions have committed, but just **notifies** other transactions that the data may not be up to date.

## Performance

SSI makes query latency much more predictable and less variable (how?) since read-only queries.

SSI is not limited to the throughput of a single CPU core. Databases like FoundationDB distributes the detection of serialization conflicts across multiple machines, allowing scaling to very high throughput.