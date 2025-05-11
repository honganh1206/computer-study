Instead of selectively activating one arithmetic circuit associating with one specific operation, the ALU *sends its operand input values to all arithmetic & logic circuits*

![[image-16.png|The ALU directs the opcode that selects one of the ALU's four arithmetic results]]

The outputs from all such circuits are sent to the multiplexer circuit to **be chosen** as the final output for the ALU

The opcode is used as the *signal input*  `S` for the multiplexer to *select which arithmetic/logic operation* as the output

Condition code output is based on the MUX output combined with circuitry to *test the output's value* to determine each condition code bit

> How the binary encoding for ADD would look like  `| OPCODE BITS (1 BYTE WIDE) | OPERAND A SOURCE | OPERAND B SOURCE | RESULT DESTINATION |`