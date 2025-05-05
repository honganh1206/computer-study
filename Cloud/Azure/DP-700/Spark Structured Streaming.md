A typical stream processing solution involves:

- Constantly reading data from a **source**
- (Optional) Manipulate the data
- Write the results to a **sink**

**Spark Structured Streaming** (SSS) provides native support for streaming with a *boundless dataframe* to capture streaming data

A SSS dataframe can read data from

- Network ports
- Real-time message brokering services e.g., Azure Event Hubs, Kafka...
- File system locations