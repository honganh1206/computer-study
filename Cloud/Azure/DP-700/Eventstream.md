---
id: Eventstream
aliases:
  - Eventstream
tags: []
---

# Eventstream

Connected to data sources and data transformation phase

For real-time data handling

## Data sources for Eventstream

External services like Event Hubs, IoT Hubs from different Azure Databases

Fabric & OneLake events

Custom endpoints from applications via Event Hub or Kafka protocols

## Data Transformations

Similar actions to the ones in SQL like Aggregate/Join/Group by/Union/Expand/Filter

## Data Destinations

Eventhouse (Go-to place) - Write to tables in KQL database, most native way to store event-based data

Lakehouse - Write directly to a delta table

Derived Stream (another Eventstream) - Require _at least_ one transformation before it can be used

Activator - Allow triggering multiple different actions-based incoming data

Custom endpoints - Allow connecting custom applications to Eventstream via Event Hub, AMQP, Kafka protocols
