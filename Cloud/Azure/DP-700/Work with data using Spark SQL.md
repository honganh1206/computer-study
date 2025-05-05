
The **Spark catalog** is a *metastore* for relational data objects such as views and tables

The Spark runtime can use the catalog to *integrate code written in Spark-supported language with SQL expressions*


```python
# Create a temporary view to make data from a dataframe available for querying
df.createOrReplaceTempView("products_view")
```

**Tables** are metadata structures that store underlying data in the storage location associated with the catalog


```python
# Save a dataframe as a table
df.write.format("delta").saveAsTable("products")
```

We can also use `spark.catalog.createExternalTable` to get data from an external storage location


```python
# Use Spark SQL API to query data
bikes_df = spark.sql("SELECT ProductID, ProductName, ListPrice \
                      FROM products \
                      WHERE Category IN ('Mountain Bikes', 'Road Bikes')")
display(bikes_df)
```

Or use SQL in a notebook


```sql
%%sql

SELECT Category, COUNT(ProductID) AS ProductCount
FROM products
GROUP BY Category
ORDER BY Category
```
