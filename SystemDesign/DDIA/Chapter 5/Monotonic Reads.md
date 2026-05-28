Users might see things *moving backward in time*, which might happen if a user requests several reads from different replicas.

When a user refreshes a page (each request is routed to a random server), the 1st query (before refresh) returns a comment added by another user, but the 2nd query (after refresh) does not show anything -> The lagging follower has yet to pick up that write.

Monotonic reads means that if one user makes several reads in sequence, they will not see old data because we ensure each user always makes their reads from the same replica.