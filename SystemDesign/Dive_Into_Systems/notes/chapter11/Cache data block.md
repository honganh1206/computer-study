Cache blocks store *multibyte chunks of program data* to take advantage of [[Spatial locality]]. 

Example: When the CPU requests the integer at address `0x1000`, it will calculate which 64-byte-aligned block contains the address `0x1000` and give a request to RAM saying "Give me the entire 64-byte (`0x40` in hex) chunk starting from the address `0x1000`". RAM returns bytes from `0x1000` to `0x103F` and the cache stores this entire 64-byte block in *one cache line* -> If the CPU access one address, it will likely need access to the addresses nearby the requested address.

The size of a cache block *determines the unit of data transfer* between the cache and main memory i.e., the cache always receives a chunk of data the size of a cache block. Usually block sizes range from 16 to 64 bytes.

> When choosing a cache's block size, cache designers must balance a trade-off: Given a fixed storage budget, a cache can store more smaller blocks (more diverse subset of memory) or fewer larger blocks (more performance for programs that has good spatial locality). This depends on the workload of applications ultimately.