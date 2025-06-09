A clock *triggers the start of each stage/phase* in [[The 4 Phases - Fetch Decode Execute WriteBack]]. The clock ensures *the inputs of each stage are ready to be used* and it also *controls the outputs of each stage*

A CPU clock measures **discrete time** (values of variables occur at distinct, separate points in time) as opposed to continuous time (variables have a particular value only for a short amount of time). 

A processor's **clock cycle time** measures *the time between each clock tick*

A processor's **clock speed** is `1/(clock cycle time)` and it is measured in megahertz (MHz) or gigahertz (GHz). A 1-MHz clock rate has *one million* clock ticks per second, and 1-GHz has *one billion* clock ticks per second

Example: If the clock rate is 1 GHz, one instruction takes 4 nanoseconds to complete, and 2 nanoseconds if the clock rate is 2 GHz

The clock rate is a *measure* of how fast the CPU can run by giving an estimate of the maximum number of instructions per second a CPU can execute

> Clock rate alone is not a meaningful metric to compare the performance of different processors. Architectures like RISC require fewer stages to execute instructions than those like CISC (See more in [[Comparing RISC and CISC]])

[[Clock rates and Processor Performance]]

[[The Clock Circuit]]

A much better measure for CPU's performance is the **cycles per instruction** (CPI).

Usually, a processor cannot maintain its maximum CPI for an entire program's execution, and a submaximum CPI is the result of many factors

