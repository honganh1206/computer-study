From Microsoft Verti-Scan technology

Designed specifically for the Parquet file format in Fabric and enabled by default

Enable lightning-fast reads, in-memory-like data access time while reducing network, disk and CPU resources

A little overhead of *15%* making writes a little slower

What do they do? Apply special sorting, group distribution, dictionary encoding and compression on Parquet files

Not beneficial for *write-intensive scenarios* where data is read only once or twice

![[image-14.png|Run the OPTIMIZE command for V-order function]]