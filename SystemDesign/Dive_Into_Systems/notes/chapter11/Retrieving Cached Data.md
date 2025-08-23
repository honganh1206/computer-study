The cache sends the requested data to the CPU's components that need it at this stage.

There is a problem: A cache data block size (64 bytes) is often larger than the amount of data the program requests (4 bytes maybe). How do we resolve this?

-> Caches use the *low-order bits* of the requested address as an **offset** to determine which bytes of a cache block the program wants to retrieve

![[image-8.png|The offset portion of an address identifies which bytes the program wants to retrieve]]



