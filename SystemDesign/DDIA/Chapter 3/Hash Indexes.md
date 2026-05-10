Simplest indexing strategy: Keep an in-memory hash map where every key is mapped to a byte offset in the data flle.

![[image.png]]

Bitcask has **KeyDir**, which is a in-memory hash map that stores every key currently in the database.

KeyDir stores a small, fixed-size structure containing:

- **File ID:** Which log file contains the data.
- **Value Size:** How many bytes to read.
- **Value Offset:** The exact byte position where the value starts in that file.
- **Timestamp:** When the entry was written.

Values can be loaded from the disk with one seek, and if they are in the file system cache, there won't be any disk I/O at all.

When to use Bitcask: Values of keys are updated frequently. Think of cat video URLs.

Avoid running out of disk space: Break the log into segments of certain sizes. Close the segment when it reaches a certain size, and open a new one for subsequent writes.

## Compaction

Throw away duplicate keys in the log, and keep the most recent updates. 

![[image-1.png]]

NOTE: We can also *merge* segments when performing compaction. This could be done on a background thread. We then route read requests to the new merged segment + delete the old segments.

![[image-2.png]]

Issues during real implementation:
1. CSV is not a good format for logs. Better use binary format that first encodes the length of string, followed by raw string.
2. When we delete the record, we append a deletion record (a tombstone). When the merging happens, the tombstone tells the merging to discard previous values for the deleted key.
3. When the database is restarted, the in-memory hash maps are lost. Bitcask solves this by capturing a snapshot of each segment's hash map, which then will be loaded into memory.
4. Partially written records: The database may crash halfway through appending a record. Bitcask files include checksums, allowing corrupted parts to be detected and ignored.
5. Concurrency control: One writer thread. Segments are append-only and otherwise immutable, so they can be read concurrently by threads.

> [!info] Append-only is a good approach
> - Sequential writes are much faster than random writes.
> - Concurrency and crash recovery with append-only segments. We certainly do not want old parts and new parts jumbling together when a crash happens mid-overwriting.
> - Avoid data fragmentation.

Hash tables have some limitations:
1. Hash tables might go out of memory when there are too many keys.
2. We have to look up each key when doing range queries like `kitty00000` and `kitty99999`