Contain multiple complete CPU cores, with each core independently scheduled by the OS

![[image-33.png|Each core has its own cache, and they share a larger cached via on-chip buses]]

Each core is a **full** CPU core containing its own complete and separate functionality to execute program instructions

So what's the fuss? A multicore processor contains **replicas** of these CPU cores with additional hardware support for the cores to *share cached data*

Each core could be scalar/superscalar/hardware multithreaded

A multicore computer can simultaneously run several sequential programs, and the OS schedule each core with a different program's instruction stream

A multicore computer can speed up the execution of a single program if the program is written as an explicitly multi-threaded (software-level threads) parallel program

