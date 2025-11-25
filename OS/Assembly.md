Calling C from Assembly

```c
/* The C function */
int sum_of_three(int arg1, int arg2, int arg3)
{
return arg1 + arg2 + arg3;
}
```

```asm
external sum_of_three ; the function sum_of_three is defined elsewhere
push dword 3 ; arg3
push dword 2 ; arg2
push dword 1 ; arg1
call sum_of_three ; call the function, the result will be in eax
```