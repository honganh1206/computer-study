### Kernel module (`.ko`)

Dynamically loadable kernel code (disabled here)

### Paravirtualization

Optimization where guest OS cooperates with hypervisor

### VirtIO

Standard for efficient virtual devices (disk, network)

### MMIO (Memory-Mapped I/O)

Devices accessed via memory addresses instead of buses like PCI

### Block device

Storage device (disk) accessed in fixed-size blocks

### initrd / initramfs

Temporary filesystem used during early boot

### devtmpfs

Kernel-managed `/dev` filesystem (device nodes)

### tty / serial console

Text-based interface for input/output

### printk

Kernel logging function (like `printf` for kernel)

### PCI

Hardware bus for attaching devices (removed here)

### EFI

Modern firmware interface (replaces BIOS)

### tmpfs

In-memory filesystem

**ELF = Executable and Linkable Format**

It’s the standard binary format Linux uses for:

- executables (`/bin/bash`)
- shared libraries (`.so`)
- the kernel (`vmlinux`)