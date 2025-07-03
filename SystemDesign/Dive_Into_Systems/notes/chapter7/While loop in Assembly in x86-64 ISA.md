 Example in C

```c
// using while loop
int sumUp(int n) {
    //initialize total and i
    int total = 0;
    int i = 1;

    while (i <= n) {  //while i is less than or equal to n
        total += i;   //add i to total
        i++;          //increment i by 1
    }
    return total;
}
```

Assembly version:

```asm
0x400526 <+0>:   push   %rbp
0x400527 <+1>:   mov    %rsp,%rbp
# update value of %rbp with %rsp
0x40052a <+4>:   mov    %edi,-0x14(%rbp)
# copy value of n to %rbp-0x14 
0x40052d <+7>:   mov    $0x0,-0x8(%rbp)
# copy 0 to %rbp-0x8 (variable total)
0x400534 <+14>:  mov    $0x1,-0x4(%rbp)
# copy value of 1 to %rbp-0x4 (variable i)
 ---
 # Heart of the loop
0x40053b <+21>:  jmp    0x400547 <sumUp+33>
0x40053d <+23>:  mov    -0x4(%rbp),%eax
# copy i to %eax
0x400540 <+26>:  add    %eax,-0x8(%rbp)
# add i to total
0x400543 <+29>:  add    $0x1,-0x4(%rbp)
# add 1 to i
0x400547 <+33>:  mov    -0x4(%rbp),%eax 
# copy i to %eax (again for next iteration)
0x40054a <+36>:  cmp    -0x14(%rbp),%eax
# compare i to n
0x40054d <+39>:  jle    0x40053d <sumUp+23>
# if condition is satisfied jump back to 53d
---
# If the branch is not taken i.e. i > n
0x40054f <+41>:  mov    -0x8(%rbp),%eax
# copy total to %eax
0x400552 <+44>:  pop    %rbp
# clean up the stack
0x400553 <+45>:  retq
# return total
```

`goto` form:

```c
int sumUp(int n) {
    int total = 0;
    int i = 1;
    goto start;
body:
    total += i;
    i += 1;
start:
    if (i <= n) {
        goto body;
    }
    return total;
}
```