## Historical evolution

|Era|Width|Register Example|Explanation|
|---|---|---|---|
|16-bit (8086)|16-bit|`AX`, `BX`, etc.|Original registers (Accumulator, Base, etc.)|
|32-bit (i386)|32-bit|`EAX`, `EBX`, etc.|"Extended" versions: `E` for **Extended**|
|64-bit (x86-64)|64-bit|`RAX`, `RBX`, etc.|`R` for **Register**, supports 64-bit|

## Semantic clarity

|Register|Width|Purpose|
|---|---|---|
|`RAX`|64-bit|Full 64-bit accumulator|
|`EAX`|32-bit|Lower 32 bits (zero-extends when written)|
|`AX`|16-bit|Lower 16 bits|
|`AH`|8-bit high|Bits 8–15 of AX|
|`AL`|8-bit low|Bits 0–7 of AX|