We are compiling an OS from an existing OS, and that will be [cross-compiling](https://wiki.osdev.org/Why_do_I_need_a_Cross_Compiler%3F)

[[Cross Compiler]]

[[Booting]]

[[Executable Format]]

[[Freestanding and Hosted Environments]]

We need a linker to link the assemble result of `boot.s` and compiled `kernel.c` as they are now both object files.

```bash
# Verify multiboot
grub-file --is-x86-multiboot myos.bin
# Check status, 0 means fine
echo $?
```