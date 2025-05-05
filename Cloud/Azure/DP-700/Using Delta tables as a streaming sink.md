Write the streamed data to a Delta table

```python
output_table_path = 'Tables/orders_processed'
checkpointpath = 'Files/delta/checkpoint'
deltastream = transformed_df.writeStream.format("delta").option("checkpointLocation", checkpointpath).start(output_table_path)

print("Streaming to orders_processed...")

# Stop the streaming data to avoid excessive processing costs
deltastream.stop()
```
