Fabric provides a starter pool to run Spark quickly with minimal configuration, and we can configure the starter pool for specific needs

![[image-5.png|Create a new starter pool]]

Some configuration settings
- Node Family - VMs used for Spark nodes
- Autoscale
- Dynamic allocation - Option to dynamically allocate executor processes or not

Apache Spark, Delta Lake and PySpark might have different versions of the Spark **runtime**, and Fabric supports this

![[image-6.png|Custom environments for multiple Spark runtimes]]

Sometimes organizations need *multiple environments* to support a diverse range of data processing tasks

## Native execution engine

A vectorized processing engine that *runs Spark directly on lakehouse infrastructure*

We can enable this at the environment level/within an individual notebook

```json
%%configure 
{ 
   "conf": {
       "spark.native.enabled": "true", 
       "spark.shuffle.manager": "org.apache.spark.shuffle.sort.ColumnarShuffleManager" 
   } 
}
```

## High concurrency mode

Enable high concurrency mode to share Spark sessions across multiple concurrent users or processes

When high concurrency mode is enabled on a notebook, **multiple users** can run code in that notebook at the same time