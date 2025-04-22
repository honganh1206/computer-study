When we reach the scheduled time, we activate the Spark cluster to execute Spark Processing to move data from the source to the destination

![[Pasted image 20250419222730.png]]

After that, then Spark cluster goes sleep

We can process data in batches too

![[Pasted image 20250419223802.png]]

Unbounded table - Data is still growing

Delta stream - Streaming query as a handle to monitor streaming

Downside: Spark needs to be run constantly, thus consuming a lot Fabric capacity

```python
# Read streaming data to unbounded table/dataframe
raw_stream_df = spark.readStream \
	.schema(file_stream) \
	.option("maxFilesPerTrigger", 1) \
	.json(source_path)

# Example transformation that adds a processed_timestamp column to a data
transformed_stream_df = raw_stream_df \
	.withColumn("processed_timestamp", \
	F.current_timestamp())

# Stream data to delta lake
delta_stream = transformed_stream_df.writeStream \
	.format("delta") \
	.outputModel("append") \
	.option("checkpointLocation", checkpoint_path) \ # Specify the directory where streaming checkpoint data is stored
	.start(f"Tables/{schema_name}/{table_name})
```