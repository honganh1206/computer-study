As C does not perform automatic array bound checking, we will encounter errors e.g., segmentation faults if we access memory outside of the bounds of an array.

However, attackers may inject malicious code that *intentionally overruns the boundary of an array* (aka buffer) to force the program to execute in an unintended manner like granting them root privilege, etc.

*The Morris Worm* exploits the `fingerd` daemon (type of process executing in the background) to replicate reports and have them sent them to the same computer multiple times, bogging down the system to an unusable state.

In the file `secretGamex86-64`,  we will *reverse engineer* the `secret` executable using GDB (Machine code is in `secret.txt`)

![[image-34.png|The call stack after the call to scanf with input 1234567890]]

Recall: ASCII encodings of digits 0 to 9 are `0x30` and `0x39`, and each stack memory location is 8 bytes long.

We can see that the input is still without array bounds (the empty space).

We read the 48 bytes (in hex) below register `%rsp` with `(gdb) x /48bx $rsp`

Sample output:

```bash
gdb) x /48bx $rsp
# First 2 addresses hold the input bytes of 1234567890
0x7fffffffdcf0: 0x31  0x32  0x33  0x34  0x35  0x36  0x37  0x38
0x7fffffffdcf8: 0x39  0x30  0x00  0x00  0x00  0x00  0x00  0x00 # Null termination byte \0 from the 3rd most significant byte onwards
0x7fffffffdd00: 0xf0  0xdd  0xff  0xff  0xff  0x7f  0x00  0x00
0x7fffffffdd08: 0x00  0x00  0x00  0x00  0x03  0x00  0x00  0x00
0x7fffffffdd10: 0xd0  0x07  0x40  0x00  0x00  0x00  0x00  0x00
0x7fffffffdd18: 0x30  0xd8  0xa2  0xf7  0xff  0x7f  0x00  0x00
```

## Secret game

If we input a really big number to `secret`, segmentation fault will happen and the return code is 139. Why? The value is so large that it *overwrites the return address below the stack frame for `main`*. The program tries to resume execution after exiting main but the return does not exist, so the program crashes with a segmentation fault.

![[image-35.png|Really huge input overwriting the value]]

The input string blew past the stated limits of the array `buf`and overwrote all other values, thus causing the program to crash. This process is known as **smashing the stack**

How to solve? We could *overwrite the stack so that the return address is replaced by the address of `endGame`*. That way, we trick the program to return 0.

[[Protection against buffer overflow]]

> The best line of defense is always the programmer. To prevent buffer overflow, we must use C functions with **length specifiers** whenever possible. We should also *add code that performs array-bound checking*.