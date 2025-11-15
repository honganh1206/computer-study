Flynn's taxonomy is commonly used to *describe the ecosystem of modern computing architecture*.

![[image.png|Flynn's taxonomy classifies the ways in which a processor applies instructions]]

A **single stream** issues one element per time unit, similar to a queue.

**Multiple streams** issue many elements per time unit (think of multiple queues)

**SISD**: Single instruction/single data systems have a single control unit processing a single stream of instruction. Most processors prior to mid-2000s were SISD machines.

**MISD**: Multiple instruction/single data systems have multiple instruction units performing on a single data stream.

**SIMD**: Single instruction/multiple data systems execute the *same* instruction on multiple data simultaneously and in **lockstep** (instructions placed in a queue, and data distributed among different compute units) fashion. Each compute unit executes the 1st instruction in the queue *simultaneously* then executes the next instruction. Example is the GPU.

**MIMD**: Multiple instruction/multiple data systems (most widely used) are flexible. Example is nearly all modern multicore CPUs.

