The ALU implements arithmetic and logic operations on both signed and unsigned integers, while *a separate floating-point unit* deals with arithmetic operations on floating-point values

The ALU takes an **opcode** (specify operation to perform) and integer operand values

Output of ALU: The resulting value of the operation and **[[Condition code]] values** that *encode information about the result*

The secret sauce: The [[ALU combines arithmetic and logic circuits with a multiplexer circuit]] to pick the ALU's output

 [[How CPUs encode operands]]

As the ALU support 4 operations (`OR/ADDER/AND/EQUALS`), the opcode must be at least 2-bit wide with four distinct values (00, 01, 10, 11), one for each operation

An ALU that performs $N$ distinct operations will need $\log_{2}(N)$ opcode bits

![[image-17.png|Opcode bits from an instruction are used to choose which operation to output]]

