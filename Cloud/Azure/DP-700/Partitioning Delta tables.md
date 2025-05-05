Improve performance by enabling **data skipping** - Skip over irrelevant data objects on an object's metadata

Example: We partition sale data by year by putting them into subfolders like `year=2021` and `year=2022`

This should only be used when you have a large amount of data + tables can be split into a few large partitions

![[image-17.png]]

> Partitions are **fixed** data layout and cannot adapt to different query patterns (?) Think first about how your data is used and its granularity


```python
# This will result in one folder "partitioned_products" with subfolders like "Category=Bike Racks"
df.write.format("delta").partitionBy("Category").saveAsTable("partitioned_products", path="abfs_path/partitioned_products")
```

With SQL


```sql
%%sql
CREATE TABLE partitioned_products (
    ProductID INTEGER,
    ProductName STRING,
    Category STRING,
    ListPrice DOUBLE
)
PARTITIONED BY (Category);
```
