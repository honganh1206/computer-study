When we create a table in Fabric lakehouse, two things happen:

1. A delta table is defined in the **metastore** for the lakehouse
2. The data for the table is stored in the Parquet files for the table


```python
# Load a file into a dataframe
df = spark.read.load('Files/mydata.csv', format='csv', header=True)

# Save the dataframe as a MANAGED delta table by Spark runtime
df.write.format("delta").saveAsTable("mytable")
```

We can also create **external tables** i.e., the relational table definition in the metastore is *mapped to an alternative file storage location*

 ```python
# Parquet data files and log files are stored in another location
df.write.format("delta").saveAsTable("myexternaltable", path="Files/myexternaltable")

# Or a fully qualified path
df.write.format("delta").saveAsTable("myexternaltable", path="abfss://my_store_url..../myexternaltable")
```

[[Create table metadata]]

[[Saving data in delta format]]

> Supposed we have a managed table that contains data files in Delta format. If we drop the table, *both the table metadata and data files are deleted*