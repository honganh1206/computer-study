A thread's ability to *easily share data with other threads* is one of its main features. Threads of a multithreaded process share the heap common to the process.

**Thread synchronization** forces threads to execute in particular order. While this adds to the runtime of the program (performance degradation), it is often necessary to *ensure program correctness*.

We use [[Mutual Exclusion]] to ensure the correctness of a threaded program, together with other common synchronization constructs like [[Semaphores]], [[Barriers]], [[Condition variables]] and [[Broadcasting]]

[[CountSort Algorithm]]

[[Data Races]]
