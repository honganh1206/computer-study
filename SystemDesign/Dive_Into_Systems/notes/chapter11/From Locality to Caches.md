
Imagine this scenario: Fiona can only have three books on her desk, and she puts up a bookshelf just outside her room. Also, the college has a huge library. This creates a book storage hierarchy"

![[image-4.png]]

## Temporal locality

Which books should Fiona move to her desk space? To make the best storage decision, Fiona need information about *future usage*

For hardware system, the system will ask the user in advance how a program will use data *regularly*, so that it can optimize the data placement.

However, in a general-purpose system like a personal computer, the user might not provide enough detail to help the system make good decisions. Thus, the system will *look to the past as a predictor of what will likely to happen in the future*. 

This is just like how Fiona would do: She would retrieve the book she needs the most to her desk, and to make space for it she will need to remove *the book she used least recently*. Fiona will do the same thing when her shelf is full as well.

This scheme captures the two temporal locality objectives well:

1. Frequently used books remain on the desk/shelf -> Make room for frequently used data in the CPU cache
2. Infrequently used books become the least recently used book, and returning them to the library makes sense -> Evict the least used data from the cache to the main memory

## Spatial locality

Fiona should retrieve *more than one book* to save her some time, and she should also retrieve additional books that are "nearby" the one she needs to save time as well.

Applying these spatial locality lessons, we can see that when retrieving data from main memory, the system should also retrieve *the data immediately surrounding it*

> Arrays are not the only example for spatial locality. A `struct` also stores a collection of related data in a contiguous region of memory, and the system should be able to identify that spatial pattern.