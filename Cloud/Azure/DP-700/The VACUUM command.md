When new Parquet files are created for update/delete requests, old ones are stored for time travel, thus accumulating Parquet files

The `VACUUM` command removes the old Parquet data files but not the transaction logs

![[image-15.png]]

`VACUUM` reads the transaction log and *permanently deletes* the files that are not currently referenced. The command also deletes the files *older than the specified retention period*

![[image-16.png]]

Alternatives

```sql
%%sql
VACUUM lakehouse2.products RETAIN 168 HOURS;

-- View previous runs
%%sql
DESCRIBE HISTORY lakehouse2.products;
```