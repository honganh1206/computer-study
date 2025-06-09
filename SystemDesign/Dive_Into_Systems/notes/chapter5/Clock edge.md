The clock edge triggers state changes in CPU circuits to drive new instructions

The **rising** clock edge (0 to 1) indicates a state in which input values are ready for the next instruction. Example is the rising edge transition signals that input values to ALU are ready

The **propagation delay**: While the clock's value is 1, the inputs spread through the circuit until the output of the circuit is ready

On the **falling** edge, the outputs are now *stable* and ready to be propagated to the next location. Example is on the falling edge, the output from the ALU is ready, and during the duration of the clock value 0 the ALU's output propagates to the register file inputs

