---
id: PySpark Overview
aliases:
  - PySpark Overview
tags: []
---

# PySpark Overview

Python API for Apache Spark

Versatile but not beginner-friendly

```py
display(person \
.agg({"*":"count"}) \
.withColumnRenamed("count(1)", "count"))

dislay(animals.filter("group == 'reptile'"))
```
