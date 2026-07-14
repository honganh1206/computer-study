Example of ACID is a $100 transaction from account A to account B:
- **Atomicity**: If account A is debited and account B is credited, but the system crashes (network failure, disk full, etc.), then the transaction is *completely cancelled* (rolled back) and the database must discard or undo any writes it has made so far.
- **Consistency**: Ensure valid state. The *total sum of money* in both accounts remains the same before and after the transaction.
- **Isolation**: Multiple transactions occur independently without inference. A single transaction can only see the balances either before or after the transfer.
- **Durability**: Permanent storage: Once the transaction is successfully committed, the new balances are saved to the databases/disks. If the server loses power, the update remains intact.

Systems that do not meet the ACID criteria are called BASE (Basically Available, Soft state, and Eventual consistency)

## Atomicity

If the writes are grouped together in an atomic transaction, and the transaction cannot be committed due to a fault, then the transaction is *aborted* (DB discards or undo any writes made so far)

## Consistency

The *application* is responsible for defining the transactions correctly to ensure consistency (the DB cannot validate invariants - true statements - of your data), while the database's properties are responsible for atomicity, isolation, and durability.

## Isolation

Concurrently executing transactions are isolated from each other. That said, each transaction can pretend it is *the only transaction running* on the entire database.

## Durability

A promise: When a transaction is successfully committed, any written data will not be forgotten, even if there is a hardware fault or the database crashes.

Perfect durability does not exist if the hard disks and all the backup are destroyed at the same time. We need a combination of risk-reduction techniques, including writing to disks, replicating to remote machines, and backups.

