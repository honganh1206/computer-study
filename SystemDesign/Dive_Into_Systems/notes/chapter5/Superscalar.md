A single processor with *multiple execution units* and *multiple execution pipelines*

A **superscalar processor** fetches *a set of instructions* from a sequential program's instruction stream and breaks them up into *multiple independent streams of instructions* that are *executed in parallel*

When we do out-of-order execution, we need to identify sequences of instructions without dependencies, so we can execute them in parallel. A superscalar processor is **out-of-order**, meaning it executes instructions not in the order the instructions appear in a sequential instruction stream

 A superscalar processor has the functionality to *create the multiple streams of independent instructions* to feed through the execution units. However, such functionality must ensure *the correct ordering* of any instruction whose execution depends on the result of a previous instruction.

A superscalar process can achieve an IPC of 5, bit it is not always the case that a scalar processor can keep all of its pipelines full