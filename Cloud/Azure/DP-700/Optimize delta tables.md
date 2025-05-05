Problem at hand

- Spark is a parallel-processing framework with data stored on one or more worker nodes
- Parquet files are *immutable*, meaning new files are written for every update/delete

For these reasons we have a *small file problem* - Queries over large amounts of data can run slowly

## `OptimizeWrite` function

Instead of writing many small files, we write fewer larger files (obviously?)

![[image-12.png]]

```python
# Optimize Write is enabled by default
# Disable Optimize Write at the Spark session level
spark.conf.set("spark.microsoft.delta.optimizeWrite.enabled", False)

# Enable Optimize Write at the Spark session level
spark.conf.set("spark.microsoft.delta.optimizeWrite.enabled", True)

print(spark.conf.get("spark.microsoft.delta.optimizeWrite.enabled"))

```

## Optimize

Consolidate small Parquet files into larger ones

![[image-13.png]]

We can also apply [[V-Order function]]

[[The VACUUM command]]

[[Partitioning Delta tables]]


