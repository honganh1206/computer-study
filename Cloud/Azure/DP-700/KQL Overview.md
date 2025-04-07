---
id: KQL Overview
aliases:
  - KQL Overview
tags: []
---

# KQL Overview

Kusto Query Language

**Read-only** request language

Can handle large volumes of structured/semi-structured/unstructured data

```kql
person
| where name == "AAA"
| project name, age

```
