The LRU policy requires *each set to store additional bits of metadata to identify which line of the set was used least recently*

More lies in a set == more bits

> The additional bits contribute to the higher complexity of set associative designs


![[image-18.png|Two-way set associative cache, each set contains two lines]]

A LRU value of 0 means leftmost line was LRU, and a LRU value of 1 means rightmost line was LRU (Note: This is just an abstraction. The interpretation of LRU bits varies across caches)

