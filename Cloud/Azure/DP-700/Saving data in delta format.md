Why do we save data in delta format without creating a table definition in the metastore?  - An useful approach when we want to *persists the results of data transformations* so we can later "overlay" a table definition or process directly by using the delta lake API


```python
# Save a dataframe in delta format
delta_path = "Files/mydatatable"
df.write.format("delta").save(delta_path)

# Replace the content in an existing folder
new_df.write.format("delta").mode("overwrite").save(delta_path)

# Add rows to existing 
new_rows_df.write.format("delta").mode("append").save(delta_path)
```
