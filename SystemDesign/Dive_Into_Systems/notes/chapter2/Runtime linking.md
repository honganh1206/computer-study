---
id: Runtime linking
aliases:
  - Runtime linking
tags: []
---

# Runtime linking

If `a.out` was created by **dynamically linking a library** from library shared objects `.so` files, then `a.out` does NOT contain copies of library functions but instead _contains information about which dynamically linked libraries are needed_

When this is needed? If `a.out` was linked with shared object files during link editing

The library code in `.so` files must be **loaded at runtime** and linked with the running program. This is called **dynamic linking**

How it works:

```bash
┌────────────────┐                  ┌─────────────────────────┐
│                │                  │                         │
│  Application   │                  │     Operating System    │
│  Executable    │                  │     Memory Space        │
│                │                  │                         │
└───────┬────────┘                  └───────────┬─────────────┘
        │                                       │
        │ 1. Application starts                 │
        │    with references to                 │
        │    shared libraries                   │
        ▼                                       │
┌────────────────┐                              │
│                │                              │
│  Dynamic       │                              │
│  Linker/Loader │◄─────────────────────────────┘
│  (ld.so)       │     2. OS invokes dynamic
│                │        linker/loader
└───────┬────────┘
        │
        │ 3. Searches for required
        │    shared libraries
        │
        ▼
┌────────────────┐     ┌────────────────┐     ┌────────────────┐
│                │     │                │     │                │
│  Shared        │     │  Shared        │     │  Shared        │
│  Library A     │     │  Library B     │     │  Library C     │
│  (libA.so)     │     │  (libB.so)     │     │  (libC.so)     │
│                │     │                │     │                │
└───────┬────────┘     └───────┬────────┘     └───────┬────────┘
        │                      │                      │
        └──────────────────────┼──────────────────────┘
                               │
                               │ 4. Maps libraries into
                               │    process memory space
                               ▼
┌──────────────────────────────────────────────────────┐
│                                                      │
│             Memory Space of Running Process          │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐   │
│  │ Application │  │ Shared Lib  │  │ Shared Lib  │   │
│  │ Code & Data │  │ A Code/Data │  │ B Code/Data │   │
│  └─────────────┘  └─────────────┘  └─────────────┘   │
│                                                      │
└──────────────────────────────────────────────────────┘
                               │
                               │ 5. Resolves symbols and
                               │    relocations at runtime
                               ▼
┌──────────────────────────────────────────────────────┐
│                                                      │
│              Application Starts Execution            │
│                                                      │
└──────────────────────────────────────────────────────┘
```

How it works? When the user runs the `a.out` with shared object dependencies, the system performs _dynamic linking_ before the program begins executing the `main` function

When the program starts executing, the linker examines the list of shared object dependencies + loads the shared object files into the running program

Runtime linking will show errors if the linker cannot find the corresponding shared object `.so`

```bash
# List the executable file's shared object dependencies
ldd a.out
```
