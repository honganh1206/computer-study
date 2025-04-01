---
id: Microsoft Fabric OneLake
aliases:
  - Microsoft Fabric OneLake
tags: []
---

# Microsoft Fabric OneLake

![[Pasted image 20250322150640.png]]

## Definition

Work as a **storage layer**

**Unified** Data Lake for the _entire organization_ - One OneLake per Fabric

SaaS version of Azure Data Lake Storage

Store files (blob-capable) + tables (relational database-capable)

Use **Delta Parquet** file as the default data format

## Benefits

### Shortcuts

- Virtualize access to data
- Eliminate data duplication
- Provide access to data in _external systems_ e.g., AWS S3, Azure DataLake, etc.

### Fabric Data Stores - Why OneLake?

When we store data in Fabric, we actually store it in OneLake with Delta Parquet as the default format

[[Serverless Compute Layer]]

[[Data Consumption Layer]]

