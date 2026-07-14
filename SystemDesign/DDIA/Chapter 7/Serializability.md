Serializable isolation allows transactions to execute in parallel, and the end result is the same as the had executed one at a time.

*Serializable isolation == strongest isolation level*. If the transactions behave correctly when running individually, they are sure to behave well when running concurrently.

Three techniques:
1. [[Actual Serial Execution]]
2. [[Two-phase Locking]]
3. [[Serializable Snapshot Isolation]]