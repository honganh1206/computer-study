Scenario: Two people editing the same Wikipedia page.

![[image-2.png]]

In a single-leader database, the 2nd writer will either block and wait for the 1st write to complete, or abort the 2nd write and ask the writer to retry.

In a multi-leader setup, both writes are successful, and the conflict is detected asynchronously at some point later in time -> Too late to resolve the conflict.

## What is a conflict?

Usual kind: Two writes concurrently modify the same field in the same record, setting two different values.

Unusual kind: Two different bookings of the same room are created at the same time. Even if we check for availability before booking, conflicts still arise if two bookings are made on different leaders.

## Conflict avoidance
Best to avoid them: If all writes go through the same leader, conflicts cannot happen.

## Resolving conflicts
The last write should determine the final value if writes are in sequential order in a single-leader setup. For a multi-leader setup, there are different ways to resolve conflicts:
- Give each write a unique ID, the one with the highest ID is declared the winner,
- Give each replica an ID, and writes originating from the replica with the higher ID always take precedence.
- Merge the writes
- Record the conflict and resolve with application code

We can write custom application code to resolve conflicts on write/read:
- On write: Bucardo allows us to write a snippet of Perl to handle conflicts
- On read: CouchDB stores all the conflicts, and the next time the data is read, the application prompts the user to resolve the conflicts and writes back to the database.

> Conflict resolution applies at row/document-level, not an entire transaction. If we use transactions to make atomically different writes, each write is still considered separate.

> Google Docs uses operational transformation, not CRDT.