The OS strives to increase the degree of multiprogramming: Keep the CPU busy while some processes are blocked waiting for I/O. 

However, since RAM is a fixed-size storage, the OS must make decisions about which process to load in RAM, possibly limiting the degree of multiprogramming. Thus, the OS can make more efficient use of system resources by *running processes with only PARTS of their virtual address spaces loaded in RAM*

[[Implementing Virtual Memory using RAM, Disk and Page Replacement]]

[[Making page accesses faster]]

