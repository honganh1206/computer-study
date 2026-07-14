Init PML4 -> PDP -> PD0 -> PT

Extract 9-bit indices to index table entries

Translate virtual address to physical address, and point kernel virtual pointer to point to the mapped region for tables.

x86-64 supports multiple page sizes. The two common ones are:
- 4 KiB pages (normal): mapped by a leaf PTE in the PT level.
- 2 MiB pages (huge/large): mapped directly by a PD entry when the PS bit is set.

A "huge page" here means a 2 MiB page mapped by a PD (page-directory) entry when the PDE64_PS (page-size) bit is set. It maps 2 MiB of linear address space with a single page-table entry instead of 512 separate 4 KiB PTEs.