 When we increase a cache's total capacity (while memory address size remains unchanged):

1. The index will increase (to have more cache lines?)
2. The tag will decrease as the index increases but the offset remains unchanged
3. The block offset remains unchanged (that same data block can hold still that much data)

Similarly, 

- If we increase the cache block's size, the offset increases, the tag remains the same (as memory address size is fixed) and so the index offset decreases
- If we increase a cache's associativity, tag will increase (more location to check for validity thus larger range), the offset remains unchanged (the same cache block's size), thus the index decreases