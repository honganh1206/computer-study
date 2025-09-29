The **translation look-aside buffer** (TLB) is a hardware cache that stores page number - frame number mappings.

When we have a TLB hit (the MMU finds a mapping in the TLB), only one RAM access is required to execute a load/store to a VA. If there is a miss, we need an additional RAM access to the page's PTE to construct a PA.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-23.png|The TLB is first searched for an entry for page p. If found, no page table lookup is needed to translate the VA to its PA.]]

With good locality, the hit rate in the TLB is very high. Most virtual memory accesses require only a single RAM access.