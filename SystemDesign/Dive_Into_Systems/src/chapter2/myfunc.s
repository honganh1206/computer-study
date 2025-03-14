.text
.globl myfunc
.type myfunc, @function
myfunc:
    pushl %ebp        # Save old base pointer
    movl %esp, %ebp   # Set new base pointer
    movl 8(%ebp), %eax  # Load argument into %eax (return value)
    leave             # Restore stack frame
    ret               # Return
