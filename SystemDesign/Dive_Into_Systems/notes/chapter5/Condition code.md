 Condition codes could specify whether the ALU result is negative/positive or if there is a carry out bit

Each condition code is encoded *in a single bit*

```c
x = 6 + 8; // Bit pattern 000 (Not negative - Not zero - No carry out value)
```

Condition codes can be used by subsequent instructions to *choose actions based on a particular condition*

 ```c
 // The condition code from the ADD instruction will decide the next jump instruction
 // Whether to execute the instruction inside (condition code == 0) the if or jump out (condition code == 1)
if ((x + 8) != 0) {
	x++;
}
```

Under the hood of implementing a jump out of the `if` body: The CPU writes the memory address of the **first instruction after the `if` body instructions** into the PC