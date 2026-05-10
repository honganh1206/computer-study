[[How Containers Work - Wizard Zines.pdf]]

OCI image is a standardized container format by Docker, just a stack of tarballs.
## Why?

Use tarball (a way to distribute code and files, short for Tape Archive)

Package all dependencies

Separate filesystem from host

A container = a group of Linux processes (MacOS running a Linux VM)

Container processes can do a lot of things but *with restrictions* (cgroup memory limit, different root dir, different PID namespace) by Linux kernel (sharing the same kernel unlike VM)

Features shared with the Linux kernel:

1. [[pivot_root]]: Set a process's root dir to a dir with the contents of the container image.
2. [[cgroup]]: Limit memory/CPU to a group of process
3. [[Namespaces]]: Allow processes to have their own network/mounts/PIDs/users/hostnames/... -> Make the process believe it's the only one running the host
4. Security: Give permissions + Prevent dangerous system calls.
5. Overlay filesystems - [[OverlayFS]] ("stack" two different directories so they appear as on): Share layers saves disk space & help containers start faster

[[Container Image]] 

[[Container Layers]]

[[Container Registries]]

## Container IP addresses

Containers use private IP addresses since they are not on public internet.

For a packet to get to the right pace, it needs a route.

## Capabilities

`CAP_SYS_ADMIN` lets you do a lot of things but avoid this.

`CAP_NET_ADMIN` allows changing network settings.

## Block scary system calls with `seccomp-bpf`

`seccomp-bpf` lets you run a *function* before every system call (like a hook)

## Configuration options

1. Map a port to a host.
2. Mount directories from the host
3. Set capabilities
4. Add `seccomp-bpf` filters
5. Set memory and CPU limits
6. Use the host network namespace.