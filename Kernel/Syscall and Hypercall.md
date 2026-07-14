Syscall: x86 instr provide fast transition from user mode to kernel mode. Faster than interrupt

Save return addr to RCX and jump to syscall_entry then route to syscall

Sysret: Exit ring 0 return to ring 3

Model-Specific Register to control CPU behavior

## Hypercall vs Syscall

| Aspect               | **SYSCALL**                   | **HYPERCALL**                          |
| -------------------- | ----------------------------- | -------------------------------------- |
| **Purpose**          | User ↔ Kernel transition      | Guest Kernel ↔ Hypervisor transition   |
| **Privilege Levels** | Ring 3 → Ring 0               | Ring 0 (guest) → Hypervisor            |
| **Who Implements**   | OS Kernel                     | Hypervisor (KVM, Xen, Hyper-V)         |
| **Mechanism**        | CPU instruction (`SYSCALL`)   | Port I/O or special instruction        |
| **Example**          | `open()`, `read()`, `write()` | `hp_open()`, `hp_read()`, `hp_write()` |
| **Used For**         | OS services                   | VM management, I/O, resources          |

```
┌─────────────────────────────────────────────────────┐
│  User Application                                   │
│  ├─ open()  ────────┐                               │
│  ├─ read()  ────────┤  SYSCALL (within same machine)|
│  └─ write() ────────┤                               │
└─────────────────────┼───────────────────────────────┘
                      │
                      ▼
            ┌──────────────────┐
            │  Guest Kernel    │
            │ (Your KVM kernel)│
            │                  │
            │  syscall_entry   │
            │  sys_open()      │───┐
            │  sys_read()      │   │
            │  sys_write()     │   │ HYPERCALL (to hypervisor)
            └──────────────────┘   │
                      │            │
                      └────────────┤
                                   ▼
                        ┌──────────────────────┐
                        │    KVM Hypervisor    │
                        │                      │
                        │  hp_open() handler   │
                        │  hp_read() handler   │
                        │  hp_write() handler  │
                        └──────────────────────┘
                                   │
                                   ▼
                        ┌──────────────────────┐
                        │    Host Machine      │
                        │   (Real File I/O)    │
                        └──────────────────────┘
```