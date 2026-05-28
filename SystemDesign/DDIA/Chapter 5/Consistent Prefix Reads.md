An observer listening to a conversation but get a mixed ordering. A conversation might go like this:

```
Mr. Poons
How far into the future can you see, Mrs. Cake?
Mrs. Cake
About ten seconds usually, Mr. Poons.
```

but to the observer:

```
Mrs. Cake
About ten seconds usually, Mr. Poons.
Mr. Poons
How far into the future can you see, Mrs. Cake?
```

Since different partitions operate differently, there is no global ordering of writes. When a user reads from the database, they may see parts of the database in an older state, and some in a newer state.

Solution: Any writes causally related to each other are written to the same partition. 