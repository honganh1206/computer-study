```sql
%%sql
-- Store the details of Internet sale orders
CREATE TABLE orders_in
(
        OrderID INT,
        OrderDate DATE,
        Customer STRING,
        Product STRING,
        Quantity INT,
        Price DECIMAL
)
USING DELTA;

-- Hypothetical data stream
INSERT INTO orders_in (OrderID, OrderDate, Customer, Product, Quantity, Price) VALUES 
	(3001, '2024-09-01', 'Yang', 'Road Bike Red', 1, 1200), 
	(3002, '2024-09-01', 'Carlson', 'Mountain Bike Silver', 1, 1500), 
	(3003, '2024-09-02', 'Wilson', 'Road Bike Yellow', 2, 1350),
	(3004, '2024-09-02', 'Yang', 'Road Front Wheel', 1, 115),
	(3005, '2024-09-02', 'Rai', 'Mountain Bike Black', 1, NULL);
```

The data is then loaded to a streaming dataframe from the Delta table

```python
# Load a streaming DataFrame from the Delta table
stream_df = spark.readStream.format("delta") \
    .option("ignoreChanges", "true") \
    .table("orders_in")

# Verify that the stream is streaming
stream_df.isStreaming
```