A clock circuit uses an [[Oscillator Circuit]] to generate a precise and regular *pulse pattern*

![[image-25.png|Each sequence of 1 and 0 makes up a clock cycle]]

A **clock cycle/tick** is a *1 and 0 subsequence from the clock circuit pattern*. 

The transition from 1 to 0 and 0 to 1 is called a [[Clock edge]]

The clock cycle is limited by *the slowest part of instruction execution*, and this part is usually the ALU stage.

The clock must be *slow enough* to allow the input signals to pass through the slowest ALU operation and produce valid outputs. Example is the ADD operation taking the longest time to complete and therefore ADD sets the *minimum time* the clock cycle must be

Since it takes 1 clock cycle to complete 1 stage of CPU instruction execution, a processor with a [[The 4 Phases - Fetch Decode Execute WriteBack]] completes *at most* one instruction every four clock cycles

![[image-26.png|Four-stage instruction execution takes four clock cycles to complete]]



