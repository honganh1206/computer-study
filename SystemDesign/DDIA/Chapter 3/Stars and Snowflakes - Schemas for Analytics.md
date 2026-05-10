Star schema a.k.a Dimensional modeling: At the center is a **fact table** to record events that occurred in a particular time

![[image-6.png]]

Snowflake schema is a variation of the star schema, where dimensions are broken down into sub-dimensions.

Tables are very wide in a data warehouse, with more than 100 columns. Dimensional tables can be very wide as well because they include metadata for analysis