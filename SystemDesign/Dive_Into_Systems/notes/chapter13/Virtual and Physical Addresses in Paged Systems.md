A virtual address (VA) will have its high-order bits specify the *page number* (on which the virtual address is stored) and its low-order bits correspond to the *byte offset* within the page.
 
Similarly, a physical address (PA) will have its high-order bits specify the *frame number* and the low-order bits specify the *byte offset* within the frame.

Because frames and pages are the same size, the byte offset bits in a VA are *identical* to the byte offset in the PA and only differ in the high-order bits.

![[image-15.png]]

How the low-order bits correspond to the byte offset: As the page size is 8 bytes, 3 low-order bits can be used to represent values from 0-7. The 13 high-order bits will be used to specify frame number

![[image-16.png|A very small system with 16-bit VA, 14-bit PA and 8-byte pages.]]


A more concrete example: VA 43357 has a byte offset of 5, page number 5419 and the high-order 13 bits, meaning the address is at byte 5 from the top of page 5419. If this page is loaded into of the physical memory, it still maintains the byte offset 5 but with a different frame number (43) due to different number of high-order bits.


## Translating VA to PA

1. Separate VA bits into page number (p) and byte offset (d) bits
2. Use the page number as an index into the page table to read PTE for virtual page (More in [[Page Tables for Virtual-To-Physical Page Mapping]])
3. Check valid bit for a valid PTE mapping.
4. Construct the physical address using five-bit frame number from the PTE as high-order bits + low-order bit offset from the virtual address as the lower-order two bits.