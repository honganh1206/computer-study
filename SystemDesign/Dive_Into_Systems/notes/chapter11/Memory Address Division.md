The **dimensions** of a cache determine how many bits to interpret as the offset/index/tag portions of a memory address.

The number of bits in each portion of the address implies what the dimensions of a cache must be?

## Offset

The offset portion must contain enough bits to refer to *every possible byte* within a cache data block. 

Supposed that a cache stores 32-byte data blocks. Since a program can ask for *any* of those 32 bytes, the cache needs enough offset bits to *describe exactly* which of the 32 possible positions the program needs.

The offset needs 5 bits to represent 32 unique values as $\log_{2}32 = 5$. Similarly, a cache that uses for bits for the offset must store 16-byte data blocks

## Index

Begin *immediately* to the left of the offset

The number of index bits is determined by the number of lines in the cache, given that *the index needs enough bits to uniquely identify every cache line*

A cache with 1024 lines needs 10 buts for the index $\log_{2}1024 = 10$

![[image-9.png|The index portion uniquely identifies a cache line, and the offset portion uniquely identifies a position in the line's data block]]


## Tag

The tag uniquely identifies the subset of memory contained within a cache line, and it *uses all of the remaining bits of the address*

The number of tag bits is $\log_{2}(x)$ with $x$ being the *distinct memory regions that map to a given cache line* i.e., the different blocks that content for the same cache line

What are the distinct memory regions? Suppose a direct-mapped cache has 4 sets of block size 16 bytes, meaning the total cache size is 64 bytes. 

Now imagine the main memory is 256 bytes in total, which begs the question "How many different memory blocks can map to set 0?". As each set has 16 bytes, that same set can be used for address 0–15, 64–79, 128–143, 192–207 … etc.

-> That is 256 /  64 = 4 different blocks that could all map to the same set. Such blocks are *distinct memory regions*

Take the 256 B memory, 64 B cache, 16 B block:

- Memory = 256 = $2^8$ addresses, so we need 8-bit addresses
- Offset = $\log_{2}(16)$ = 4 bits
- Sets = 4 so index = $\log_{2}(4)$ = 2 bits
- Tag = 8 - (4 + 2) = 2 bits = $\log_{2}(4)$ with 4 distinct memory regions as shown above

[[Cache configuration effects]]
