## SSTables

SSTables stand for **Sorted String Tables**, where we require *the sequence of key-value pairs is sorted by key*.

Advantages of SSTables over log segments and hash indexes;

1. Merging segments is simpler and more efficient with the mergesort: Look at the 1st key in each file -> Copy the lowest key to the merged output file. For one key appearing in several segments, we keep the value of the most recent segment (like handicap in example below)

![[image-5.png]]

2. No need for an in-memory hash map of *all* keys: When we don't know the offset of the word "handiwork" but we know the offsets of "handbag" and "handsome", we can jump straight to the offset of "handbag" and scan from there.

![[image-4.png]]

3. Group requests into blocks for ranged read requests: We compress records into blocks before writing into disks. The indexes then point at the start of the compressed blocks.

### Constructing and maintaining SSTables

Maintaining a sorted structure in memory is easier than that on disk. We can use tree data structures like red-black trees and AVL trees (both are balanced binary search trees).

---
## Log-Structured Merge-Tree

1. When a write comes in, add it to an in-memory balanced tree data structure (a memtable)
2. When the memtable exceeds the threshold, write it out to disk as an SSTables file. New writes can continue to a new memtable.
3. When there is a read request, we search from the memtable -> most recent on-disk SSTables segment -> older ones.
4. Run merging and compaction process in the background.

We keep a separate log on disk to which every write is *immediately* appended, in case the database crashes, to restore the memtable.

### Lucene

An indexing engine, given a word in a search query, find all documents that mention the word. The word is the key and the value is list of document IDs.

### Performance optimizations

LSM-tree algorithm can be slow since we need to check the memtable -> most recent segment -> older segments. We optimize this by using **Bloom filters** (a data structure to approximate the contents of a set), which tells us if a key exists in the database or not.

To determine the order and timing of how SSTables are compacted and merged, we have options like *size-tiered* (new and small SSTables are merged into older and larger SSTables) and *leveled compaction* (split up key range into smaller SSTables and old data is moved into separate levels, allowing incremental compactions instead of processing the entire dataset at once).