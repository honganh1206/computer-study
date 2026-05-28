Read-scaling architecture: Create many followers, distribute read requests across these followers.

-> This only works with asynchronous replication. If one synchronous node is down, it would make the entire system unavailable for writing (See [[Synchronous vs Asynchronous Replication]])

However, with asynchronous replication, we may see outdated information if the follower has fallen behind because *not all writes have been reflected in the follower*.

## Reading your own writes

If the user views the data shortly after making a write, the new data may not yet have reached the replica. This might happen with asynchronous replication.

In this case, we need *read-after-write consistency*, which guarantees that if the user reloads the page, they will always see updates they submitted themselves.

How to implement:
- When reading something the user may have modified, read it from the leader, otherwise the follower.
- If most things on the application are editable by the user, most things then should be read from the leader.
- The client can remember the timestamp of the most recent write, then the system must ensures any replica serving reads for that user must reflects updates at least until that timestamp.

Complexity increases when the same user use multiple devices. For that we need *cross-device read-after-write consistency*. Issues to consider:
- Centralize metadata like last update time, since one device probably not know about updates on the other device.
- Route requests from all of a user's devices to the same data center.

[[Monotonic Reads]]

[[Consistent Prefix Reads]]

## Solution

Think about how the application behaves if the replication lag increases to several minutes or even an hour.

We can perform a certain kinds of reads on the leader, but that is easy to get wrong on the application code.

We can just trust the database to do the right thing. This is why *transactions* exist.