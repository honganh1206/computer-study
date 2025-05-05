
After reading the data from Delta tables to a streaming dataframe, we can use SSS API to process it

An example would be counting the number of orders placed every minute and send the aggregated results to a downstream process

```python
# Filters out rows where the `Price` column is `null`
# And add two columns `IsBike` and `Total`
from pyspark.sql.functions import col, expr

transformed_df = stream_df.filter(col("Price").isNotNull()) \
    .withColumn('IsBike', expr("INSTR(Product, 'Bike') > 0").cast('int')) \
    .withColumn('Total', expr("Quantity * Price").cast('decimal'))
```
