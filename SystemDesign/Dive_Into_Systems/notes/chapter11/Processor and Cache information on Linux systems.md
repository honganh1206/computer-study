The `lscpu` command displays information about the processor

Consider the following command execution:

```sh
$ lscpu
...
CPU(s):                          12
Thread(s) per core:              2
Core(s) per socket:              6
Socket(s):                       1
...
L1d cache:                       192 KiB
L1i cache:                       384 KiB
L2 cache:                        3 MiB
L3 cache:                        16 MiB
```

There are six total cores (`Socket X Core(s) per socket`) and each core is two-way hyperthreaded (`Thread(s) per core`)

Three level of caches, with L1 having two separate caches: One for caching data `L1d` and one for caching instructions `L1i`

We can also see files in `/proc` and `/sys` filesystems, which contain information about the processor. The following command lists information about the caches for a specific processor core:

```sh
# 4 caches in this example
$ ls /sys/devices/system/cpu/cpu0/cache
index0/  index1/  index2/  index3/
```

Some more commands to check more metadata

```sh
# Core 0 has separate data and instruction caches
$ cat /sys/devices/system/cpu/cpu0/cache/index*/type
Data
Instruction
Unified
Unified
# Data and instruction caches are both L1 caches
$ cat /sys/devices/system/cpu/cpu0/cache/index*/level
1
1
2
3
# L1 and L2 are private to core 0, while L3 is shared by all 6 cores
$ cat /sys/devices/system/cpu/cpu0/cache/index*/shared_cpu_list
0,6
0,6
0,6
0-11
```

