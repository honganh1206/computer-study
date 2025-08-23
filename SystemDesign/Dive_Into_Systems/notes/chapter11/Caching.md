A small, fast device on a CPU that *holds limited subsets of main memory*.

Questions to answer:

1. *Which* subsets of a program's memory should the cache hold?
2. *When* should the cache copy of a subset of a program's data from the main memory to the cache or vice versa?
3. *How* can a system determine whether a program's data is present in the cache?

[[Cache behavior and terminology]]

[[Direct-Mapped Caches]]

[[Cache Misses and Associative Designs]]

[[Set Associative Caches]]

[[Cache Analysis with Cachegrind]]

## Exercises

(?) Consider a statically allocated 2D int array in C, declared as `int array[3][3]` that is initialized by a program in some way, such that its contents in memory are the following:

```c
Memory address | Data
0x FF00 0BB0   |    1
0x FF00 0BB4   |    2
0x FF00 0BB8   |    3
0x FF00 0BBC   |   10
0x FF00 0BC0   |   20
0x FF00 0BC4   |   30
0x FF00 0BC8   |  100
0x FF00 0BCC   |  200
0x FF00 0BD0   |  300
```
```
```
During execution, data from consecutive memory addresses are loaded into the CPU cache in 16-byte blocks. Assuming the array is copied into the cache starting from element `array[0][0]`. Which array values are included in the second block loaded into the cache?

-> 20, 30, 100, 200

Since the CPU cache loads memory in 16-byte blocks i.e., cache line size is 16 bytes, and each `int` is 4 bytes, the first block will store values from `array[0][0]` to `array[1][0]` i.e., 1,2,3 and 10

Following the same logic, the 2nd cache block will store values from `array[1][1]` to `array[2][1]` i.e., 20, 30, 100, 200

(?) Assume that you have memory address X. Will X + 1 have the same set index as X, or will it have the same tag as X

-> Neither. Supposed that the byte offset of X contains all 1's `X = 0b ... 00 01 1111`, adding +1 to X `X+1 = 0b ... 00 10 0000` will increase the index by one, which will map X+1 to a different set. The same thing happens with tag: Doing so increase the tag by 1.

(?) Let A, B, C, D, E, and F be memory addresses that have the same index but different tags.

If these addresses are accessed in this order: ABCDEFABCDEF. Assume that the cache is initially empty (all blocks are marked invalid) and associative caches use LRU replacement.

The number of misses for

- A direct-mapped cache is 12/12
- A 2-way set associative cache is 12/12
- A 4-way set associative cache is 12/12

**Explain**: ABCDEF is 5 distinct references before either one of them is used again, so the reuse distance here is 5

(?) Let A, B, C, D, be memory addresses that have the same index but different tags.

If these addresses are accessed in this order: AABBCCDDAABBCCDD

Assume that the cache is initially empty (all blocks are marked invalid) and associative caches use LRU replacement.

The number of misses for

- A direct-mapped cache is 8/16
- A 2-way set associative cache is 8/16
- A 4-way set associative cache is 4/16

**Explain**:  Each pair (`AA`, `BB`, `CC`, `DD`) behaves as **miss then hit** because the same block is still there for the second access, but the next different tag evicts it.

The reuse distance alternates a 0 (the immediate second of each pair - qualify for direct-mapped and 2-way) and 3 (the later return - qualify for 4-way)

(?) Let A, B, C, D, E, and F be memory addresses that have the same index but different tags.

If these addresses are accessed in this order: EFFEDCBAABCD

> List the possible reuse distance values i.e., number of distinct references between two identical references e.g., EFFE has a reuse distance of 1

Assume that the cache is initially empty (all blocks are marked invalid) and associative caches use LRU replacement.

The number of misses for

- A direct-mapped cache is 10/12
- A 2-way set associative cache is /12
- A 4-way set associative cache is /12

**Explain**: The reuse distance alternates between 0, 1, 2 and 3

Direct-mapped: Qualify for 0 only ($1-1=0\leq 0$)  so only immediate duplicates are hits (FF and AA)

2-way: Qualify for 0 and 1 ($2-1 = 1 \leq 1$) so immediate duplicates and 1-distinct-value-between are hits (FF, AA , EFFE, BAAB)

4-way: Qualify for 0, 1, 2 and 3 ($4-1=3 \leq 3$) so we have  immediate duplicates and 1/2/3-distinct-value-between are hits (FF, AA, EFFE, BAAB, CBAABC. DCBAABCD)