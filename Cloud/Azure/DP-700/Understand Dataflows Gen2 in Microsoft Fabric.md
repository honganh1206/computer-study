---
id: Understand Dataflows Gen2 in Microsoft Fabric
aliases:
  - Understand Dataflows Gen2 in Microsoft Fabric
tags: []
---

# Understand Dataflows Gen2 in Microsoft Fabric

Dataflows Gen2 can _connect to various data sources_, then _prepare and transform the data_

[[Dataflows]]

## How to use Dataflows Gen2

- (Traditional) Use Power Query Online to extract, transform, and load data into a consumable format
- (Use the [data pipeline](./Data pipelines.md) only) Copy the data, then use programming languages to extract, transform and load the data
- (Use the data pipeline and Dataflows Gen2) Use the pipeline to extract and load the data to a preferred destination -> Use Dataflows Gen2 to connect to the data storage then cleanse + transform the data

## Benefits and limitations

### Benefits

- Extend data with consistent data
- Allow self-service user access to data
- Optimize performance e.g., extract data once for reuse
- Simplify data source complexity
- Ensure consistency and quality of data by transforming it before loading
- Simplify data integration by providing a low-code interface

### Limitations

- Not a replacement for data warehouses
- No support for row-level security
- Require Fabric capacity workspace
