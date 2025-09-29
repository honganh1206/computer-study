Since every page of a VAS can map to a different frame in RAM, the OS must maintain mappings for every virtual page in the process's address space.

For that, the OS keeps a per-process **page table** - a data structure to store the mappings between the process's virtual page number and physical frame number.

![[image-17.png|Page tables, stored in RAM, are used by the system to translate process's virtual addresses to physical addresses to address locations in RAM]]

For each page, the page table stores one *page table entry* (PTE) containing the frame number to the frame that stores the page. A PTE can hold some more information, like a *valid bit* to indicate whether the PTE stores a valid mapping.

![[image-18.png|A PTE stores the frame number 23 of the frame of RAM where the virtual page is loaded.]]


## Using the Page Table for mapping

There are **four steps** to translate a virtual address to physical address

![[image-19.png]]

1. For a page size of $2^k$ bytes, the low-order k bits (VA bits (k-1) to 0) encode the byte offset (d), and the high-order N-k bits (VA bits (N-1) to k) encode the virtual page number (p). This is done by the MMU.
2. The page number is used by MMU as an index for the page table to access the PTE for page p. The **page table base register** (PTBR) stores the RAM address of the process's page table, and its value is combined with page number value (p) to compute the address of the PTE for page p.
3. If the valid bit is 1, then the mapping is valid. Otherwise a page fault occurs, triggering the OS to handle faulty address translation.
4. The MMU constructs the physical address using frame number (f) from the PTE + page offset (d) bits from the VA

## Example: Mapping VA to PA with a Page Table

Consider a tiny paging system:

- 4-byte page size
- 6-bit VA (high-order 4 bits and low-order 2 bits)
- 7-bit PA

Assuming the page table for process P1 looks like this:

|Entry|Valid|Frame #|
|---|---|---|
|0 (0b0000)|1|23 (0b10111)|
|1 (0b0001)|0|17 (0b10001)|
|2 (0b0010)|1|11 (0b01011)|
|3 (0b0011)|1|16 (0b10000)|
|4 (0b0100)|0|08 (0b01000)|
|5 (0b0101)|1|14 (0b01110)|
|…​|…​|…​|
|15 (0b1111)|1|30 (0b11110)|

Some important things about this table:

- The number of entries/size of the table is determined by the number of bits and the page size. The high-order 4 bits specifies determines 16 ($2^4$) total pages of virtual memory.
- The size of PTE depends on the number of bits in PA + the page size. As the frame number requires 5 bits (high-order), each PTE needs 6 bits (1 more for the frame number)
- The *maximum* sizes of virtual and physical memory are determined by the number of bits in the addresses. For example, because virtual addresses are 6 bits, so each virtual address space is $2^6=64$ bytes
- Page size + number of bits in VA and PA + page table determines the mapping. If a process loads a value from its virtual address, the page table must convert the virtual address to the physical address to access the value in RAM.


## Example: Virtual-to-Physical Address Mappings of two processes

Scenario: 8-byte pages, 7-bit virtual addresses, 6-bit physical address

| P1's Page Table |       |       | P2's Page Table |       |       |
| --------------- | ----- | ----- | --------------- | ----- | ----- |
| Entry           | Valid | Frame | Entry           | Valid | Frame |
| 0               | 1     | 3     | 0               | 1     | 1     |
| 1               | 1     | 2     | 1               | 1     | 4     |
| 2               | 1     | 6     | 2               | 1     | 5     |
| ...             |       |       |                 |       |       |
| 11              | 1     | 7     | 11              | 0     | 3     |
| ...             |       |       |                 |       |       |
|                 |       |       |                 |       |       |
We are going to calculate the physical addresses for the following sequence of virtual memory addresses:

```css
P1: 0000100
P1: 0000000
P1: 0010000
              <---- context switch
P2: 0010000
P2: 0001010
P2: 1011001
              <---- context switch
P1: 1011001
```

### Step 1: Determine the division of bits in VA and PA

8-byte ($2^3$) page size -> Three low-order bits of every address encodes the page offset.

7-bit VA -> Three bits for the page offset, four bits for specifying page number (p)

6-bit PA -> Three bits for page offset and the last 3 for frame number (f)

### Step 2: Look up the process's page table

We use the page number bits (p) to look up the PTE for page p in the process's page table.

If the valid bit is set for the PTE, we generate the PA by combining the frame number (f) with the low-order bits of the PA (d) (coming from the byte-offset bits of the VA)

The result is this table below:

| Process                 | VA      | p    | d   | PTE                     | f                            | d   | PA                                        |
| ----------------------- | ------- | ---- | --- | ----------------------- | ---------------------------- | --- | ----------------------------------------- |
| P1                      | 0000100 | 0000 | 100 | PT 0: 1(v - valid),3(f) | 011                          | 100 | 011100                                    |
| P1                      | 0000000 | 0000 | 000 | PT 0: 1(v), 3(f)        | 011                          | 000 | 011000                                    |
| P1                      | 0010000 | 0010 | 000 | PT 2: 1(v), 6(f)        | 110                          | 000 | 110000                                    |
| Context switch P1 to P2 |         |      |     |                         |                              |     |                                           |
| P2                      | 0010000 | 0010 | 000 | PT[2]: 1(v),5(f)        | 101                          | 000 | 101000 (Same VA with P1 but different PA) |
| P2                      | 0001010 | 0001 | 010 | PT[1]: 1(v),4(f)        | 100                          | 010 | 100010                                    |
| P2                      | 1011001 | 1011 | 001 | PT[11]: 0(v),3(f)       | **page fault (valid bit 0)** |     |                                           |
| Context switch P2 to P1 |         |      |     |                         |                              |     |                                           |
| P1                      | 1011001 | 1011 | 001 | PT[11]: 1(v),7(f)       | 111                          | 001 | 111001                                    |
When P1 accesses its virtual address 8 (0b0000100), the address is divided into its page number 0 (0b0000) and its byte offset 4 (0b100).

The page number (0) is used to look up PTE entry 0 with valid bit as 1 (valid mapping entry) and frame number as 3 (0b100). The PA is constructed using the frame number + byte offset of the VA (0b011100)

When process P2 is context switched on the CPU, its page table mappings are used instead.