Indexes slow down writes, and append-only is the most performative approach.

[[Hash Indexes]]

[[SSTables and LSM-Trees]]

[[B-Trees]]

## Compare B-Trees and LSM-Trees


|               | LSM-Trees<br>                                                                                                                                                                | B-Trees                                                                                      |
| ------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| Advantages    | 1. Faster for writes<br>2. Sustain higher write throughput<br>3. Better compression and produce smaller files                                                                | 1. Faster for reads<br>2. One key in one place, better for transaction isolation using locks |
| Disadvantages | 1. Compaction process might interfere with the performance of read and write operations<br>2. Sharing disk bandwidth between high write throughput and compaction<br>3. <br> | Fragmentation occurs when splitting pages leading to unused space                            |

## Other indexing structures

The place where rows is known as the **heap file**, and it stores data in no particular order. 

The heap file prevents duplicating data when there are multiple indexes, since each index just refers to a location in a heap file, while the actual data is stored in one place.

When updating a value without changing the key, we usually overwrite the record given the old value > new value. When new value > old value, the value must be moved somewhere, and the indexes must be updated to point at new locations in the heap.

A **covering index** is a *compromise* between the clustered index and a non-cluster index, which stores *some* of a table's column within the index. This allows the database engine to return results immediately from the index tree without additional disk seeks.

### Multi-column indexes

**Concatenated/Composite indexes** where we combine several fields into one key by appending one column to another. The index definition specifies which order the fields are concatenated.

```sql
-- Creating a concatenated index on three columns
CREATE INDEX employees_ix ON employees (last_name, job_id, salary);
```

**Multidimensional indexes** are to query several columns at once, important for geospatial data.

```sql
SELECT * FROM restaurants WHERE latitude > 51.4946 AND latitude < 51.5079
						AND longitude > -0.1162 AND longitude < -0.1004;
```

### Full-text search and fuzzy indexes

Fuzzy search: Search for *similar* keys such as misspelled words.

Full-text search: Search for one word to be expanded to include synonyms of the word, also ignore grammatical variations and search for occurrences of words near each other.

Levenshtein automation supports efficient search for words within a given edit distance.

## In-memory databases

The idea is to keep not-so-big datasets entirely in memory, distributed across machines. Acceptable to be lost during machine restarts.

In-memory databases are faster because they avoid the overhead of encoding in-memory data structures in a form that can be written to disk.

In-memory databases provide data models that are difficult to implement with disk-based indexes like queues and sets.

In-memory databases can support datasets larger than available memory with *anti-caching*: Evicting the LRU data from memory to disk where there is not enough memory, and load it again in the future.