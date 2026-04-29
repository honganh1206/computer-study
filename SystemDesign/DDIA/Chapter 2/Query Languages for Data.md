SQL is a *declarative* query language. We specify the pattern of data that we want without telling how to achieve that goal.

SQL is more limited in functionality due to its declarative nature (no guarantee of any particular ordering compared to imperative code), but that provides more room for automatic optimizations since imperative code relies on ordering. 

SQL is better for parallel execution, since imperative code is hard to parallel across multiple cores and machines and *instructions must be executed in a particular order*.

[[MapReduce]]

[[MapReduce Querying]]