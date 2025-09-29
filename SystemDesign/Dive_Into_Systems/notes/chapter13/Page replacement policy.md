Tags: #review 

The OS runs a **page replacement policy** when free RAM is exhausted in the system.

## How does it work?

The policy picks a frame of RAM being used and replaces its content with the faulted page by *evicting the current page from RAM*.

To do so, the OS needs a good page replacement policy to select with frame will be written back to disk. For example, an OS might implement the **Least Recently Used** policy (Refer to [[Least recently used (LRU) line]]) to replace the page stored in the RAM frame that has been accessed least recently.

> LRU works well when there is a high degree of locality in memory accesses.

