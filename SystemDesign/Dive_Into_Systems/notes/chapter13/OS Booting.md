Here the OS "pulls itself up by its bootstraps", but it still needs some help to load itself onto the computer to run its boot code.

-> To do so, code stored in computer firmware (nonvolatile memory in the hardware?) runs when the computer first powers up. Examples of such firmware are **BIOS** (Basic Input/Output System) and **UEFI** (Unified Extensible Firmware Interface)

On power-up, BIOS/UEFI runs and does *just enough* hardware initialization to load *the 1st chunk of the OS* i.e., its boot block, from disk to RAM and to start running boot block instructions on the CPU.

Once the OS starts running, it loads the rest of itself from disk and complete the initialization for the users.

