In a **row-oriented** database, a "row" is a single unit. All data for "User A" (Name, Age, Email) is stored physically next to each other. If you move the row, the data stays together.

In **column-oriented** storage, that relationship is not physical; it is **positional**.

Focus on storing facts. Examples are DuckDB and ClickHouse. Good for analytics.

Most analytics work only need 4-5 columns out of 100 columns in a table.

In most OLTP databases, storage is laid out in *row-oriented* fashion: All values from one row of a table are stored next to each other (like an array? physically?). Document databases as well (one contiguous sequence of bytes).

The idea of column-oriented storage: Store all values from each column together instead, not those from each row.

![[image-7.png]]

## Column Compression

> In general, we take a column with $n$ distinct values and turn it into $n$ separate bitmaps. One bitmap for one distinct value, and one bit for each row. The bit is 1 if the row has the value we are searching for.

Common technique is **bitmap encoding**:

![[image-8.png]]


We create one binary vector per unique value (bitmap for each possible value), and each bitmap has length = number of rows (1 means row has values and 0 means does not have)

When we scan for `product_sk = 31`, we have

```
Positions:      0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
Column value:   69 69 69 69 74 31 31 31 31 29 30 30 31 31 31 68 69 69

Bitmap (31):    0  0  0  0  0  1  1  1  1  0  0  0  1  1  1  0  0  0
```

So instead of storing 18 integers, you now store **6 bitmaps of length 18**.

## Memory bandwidth and vectorized processing

Many bottlenecks: Bandwidth to get data from disk -> memory/memory -> CPU cache, branch mispredictions, etc.

Column-oriented storage layouts are good to make use of efficient CPU cycles, as the CPU can tight-loop through the compressed chunk of column data.

Operators like AND or OR can be designed to operate on compressed chunks of column data -> Vectorized processing.

## Sort Order in Column Storage

Store the rows in the order they were inserted, or impose an order.

We should not sort each column independently, since when reconstruct the rows, the data is corrupted. Imagine this table:

|Name|Age|
|:--|:--|
|Zebra|10|
|Apple|50|
|Monkey|30|
In **column-oriented storage**, this is stored as two separate arrays:

- **Column `Name`**: `[Zebra, Apple, Monkey]`
- **Column `Age`**: `[10, 50, 30]`

After sorting:

- **Index 0:** Apple is 10  **WRONG** (Apple was 50)
- **Index 1:** Monkey is 30  (Correct by coincidence)
- **Index 2:** Zebra is 50  **WRONG** (Zebra was 10)

Sorted order helps with compression of columns, especially with the first sort key

### Different sort orders

Multiple sort orders = multiple secondary indexes

Row-oriented store keeps every row in one place with a clustered index (which defines the physical order of data storage), and secondary indexes contain pointers to matching rows.

## Writing to Column-Oriented Storage

Optimization techniques like compression and sorting order make writes more challenging (harder to append like row-oriented storage). 

A solution is LSM-trees: Writes are stored in memory and prepared to be written to disk later. When enough writes accumulate, they are merged with the column files on disks and written to new files in bulk.

