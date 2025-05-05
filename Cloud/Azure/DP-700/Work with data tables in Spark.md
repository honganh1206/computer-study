We can use Spark SQL to work with data in delta tables by using the `spark.sql` library

 ```python
spark.sql("INSERT INTO products VALUES (1, 'Widget', 'Accessories', 2.99)")
```

or SQL

```sql
%%sql

UPDATE products
SET Price = 2.49 WHERE ProductId = 1;
```

We can also use Delta API if we work with delta files more than catalog tables

```python
from delta.tables import *
from pyspark.sql.functions import *

# Create a DeltaTable object
delta_path = "Files/mytable"
deltaTable = DeltaTable.forPath(spark, delta_path)

# Update the table (reduce price of accessories by 10%)
deltaTable.update(
    condition = "Category == 'Accessories'",
    set = { "Price": "Price * 0.9" })
```

We can use **time travel** to work with table versioning

 ```sql
%%sql
-- See the history of a table
DESCRIBE HISTORY products
-- See the history of an external table
DESCRIBE HISTORY 'Files/mytable'
```

Or do it with PySpark

```python
# Set the version to see
df = spark.read.format("delta").option("versionAsOf", 0).load(delta_path)
# Or use timestamp instead
df = spark.read.format("delta").option("timestampAsOf", '2022-01-01').load(delta_path)
```
