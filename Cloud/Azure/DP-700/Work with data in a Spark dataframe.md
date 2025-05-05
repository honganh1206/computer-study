Spark natively uses a data structure called **resilient distributed dataset (RDD)** and we can write code that works directly with RDD

More commonly used data structure is the **dataframe** provided by the Spark SQL library


```python
# Data
ProductID,ProductName,Category,ListPrice
771,"Mountain-100 Silver, 38",Mountain Bikes,3399.9900
772,"Mountain-100 Silver, 42",Mountain Bikes,3399.9900
773,"Mountain-100 Silver, 44",Mountain Bikes,3399.9900
...

# Infer a schema
%%pyspark # MAGIC that tells Spark the language we use in this cell
df = spark.read.load('Files/data/products.csv',
    format='csv',
    header=True
)
display(df.limit(10))

# Specify a schema
from pyspark.sql.types import *
from pyspark.sql.functions import *

productSchema = StructType([
    StructField("ProductID", IntegerType()),
    StructField("ProductName", StringType()),
    StructField("Category", StringType()),
    StructField("ListPrice", FloatType())
    ])

df = spark.read.load('Files/data/product-data.csv',
    format='csv',
    schema=productSchema,
    header=False)
display(df.limit(10))

# Filtering and grouping

bikes_df = df.select("ProductName", "Category", "ListPrice").where((df["Category"]=="Mountain Bikes") | (df["Category"]=="Road Bikes"))
display(bikes_df)

counts_df = df.select("ProductID", "Category").groupBy("Category").count()
display(counts_df)

# Save a dataframe into a parquet file in the data lake
bikes_df.write.mode("overwrite").parquet('Files/product_data/bikes.parquet')

# Partition the output file
bikes_df.write.partitionBy("Category").mode("overwrite").parquet("Files/bike_data")
# The output is a bike_data folder containing these subfolders: Category=Mountain Bikes and Category=Road Bikes

# Load partitioned data
road_bikes_df = spark.read.parquet('Files/bike_data/Category=Road Bikes')
display(road_bikes_df.limit(5))


```
