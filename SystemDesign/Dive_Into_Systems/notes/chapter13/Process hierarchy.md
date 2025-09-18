When there are parent-child relationships between the set of active processes, we have a **process hierarchy**

If process A makes two calls to `fork`, two new child processes are created B and C. The child processes will continue creating child processes, making a hierarchy.

![[image-6.png]]


> A system needs at least one process to create any new processes, since existing processes trigger process creation.

At boot time, the OS creates the 1st user-level process in the system named `init`, and it sits at the very top of the hierarchy.