An operation is defined as being **atomic** if *a thread perceives it as executing without interruption (all or nothing)*. In other words, the subset of code must execute *in isolation* to ensure atomicity.

In some libraries, we use a keyword or type to specify a particular block of computation should be treated as atomic.

Both `counts[1] = counts[1] + 1` and `counts[1]++` are not atomic, because both lines actually correspond to several instructions at the machine level.

We thus need a *synchronization construct* like [[Mutual Exclusion]].

> [!tip]
> All operations should be assumed to be non-atomic unless mutual exclusion is explicitly enforced.