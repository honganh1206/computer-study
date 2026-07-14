---
id: Compiling C code
aliases:
  - Compiling C code
tags: []
---

# Compiling C code

The C compiler translate the C source file `.c` to an executable binary file `.out` in four distinct steps: Precompiling -> Compiling -> Assembling -> Linking

```mermaid
graph TD
    %% Source Files
    subgraph Source Files
        M[main.c]
        A[add.c]
        S[sub.c]
    end

    %% GCC Processing Stage 1
    subgraph GCC Stages 1-3
        M -->|gcc -c| MO[main.o]
        A -->|gcc -c| AO[add.o]
        S -->|gcc -c| SO[sub.o]
    end

    %% File Types Styling
    style MO fill:#f9f,stroke:#333,stroke-width:2px
    style AO fill:#f9f,stroke:#333,stroke-width:2px
    style SO fill:#f9f,stroke:#333,stroke-width:2px

    %% Archiving Stage
    subgraph Archiving
        AO -->|ar rcs| LA[libmymath.a]
        SO -->|ar rcs| LA
    end
    style LA fill:#bbf,stroke:#333,stroke-width:2px

    %% Linking Stage
    subgraph GCC Stage 4: Linking
        MO -->|gcc main.o libmymath.a| Linker[Linker]
        LA -->|gcc main.o libmymath.a| Linker
        Linker --> EXE[my_program]
    end
    style EXE fill:#bfb,stroke:#333,stroke-width:4px

    %% Explanations
    classDef note fill:#fff,stroke:#ccc,stroke-dasharray: 5 5;
    class M,A,S,MO,AO,SO,LA,EXE note;
```

[[Precompiling]]

[[Compiling]]

[[Assembling]]

[[Linking]]

[[Common compilation errors]]
