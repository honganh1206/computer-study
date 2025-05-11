Improve data quality as it moves through different layers. More like a framework for data cleaning

![[image-22.png]]

Guarantee data is reliable and consistent as it goes through checks and changes

## Bronze layer

Landing zone for all kinds of data (structured/semi-structured/unstructured) in its original format

## Silver layer

Combining & merging data and enforcing data validation rules

Act as a *central repository* across an organization or team where data is stored in a consistent format

## Gold layer

Further refinement to align with specific business and analytical needs e.g., aggregating data to a particular granularity, enriching it with external information, etc.

> We can customize the medallion architecture like adding a "raw" or "platinum" layer

## Moving data across layers in Fabric

Consider these before doing so:

- How much data we are working with?
- How complex the transformations?
- How often do we need to move data?
- Comfortable tools to use?

> Data transformation (altering the structure or content of data) is not data orchestration (coordinating and managing multiple data-related processes)

## Implementation steps

1. Set up the foundation by creating a lakehouse
2. Design the layers and determine how data will flow between them
3. Ingest data into bronze
4. Transform data and load to silver
5. Generate a gold layer
6. Enable downstream consumption

