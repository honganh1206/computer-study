> Enable the OS to make efficient use of hardware resources.

> [!example]
> When a process running on a CPU needs to access data on disk, rather than have the CPU sit idle for the data to be read into memory, the OS can *give the CPU to another process* and let it run, while the read operation will be handled by the disk.

By using multiprogramming, the OS can *mitigate some effects of the memory hierarchy on its program* by keeping the CPU busy executing some processes, while other processes are waiting to access data from lower levels of the memory hierarchy.

[[Timesharing]]

[[Context Switching]]

