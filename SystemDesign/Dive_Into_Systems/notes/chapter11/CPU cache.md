CPU cache occupies the middle ground between registers and the main memory

A CPU cache stores a few kilobytes to megabytes of data *directly on the CPU*, but not as close to the ALU as registers. Thus, they are faster to access compared to the main memory, but require more cycles than registers to make the data available

How the data is loaded into the CPU cache? The programmer does not explicitly load values into the cache - the control circuitry in the CPI will *automatically* store a subset of the main memory's contents in the cache.