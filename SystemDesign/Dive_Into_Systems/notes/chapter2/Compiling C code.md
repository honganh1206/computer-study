---
id: Compiling C code
aliases:
  - Compiling C code
tags: []
---

# Compiling C code

The C compiler translate the C source file `.c` to an executable binary file `.out` in four distinct steps: Precompiling -> Compiling -> Assembling -> Linking

```js
SOURCE CODE           PREPROCESSING          COMPILATION           ASSEMBLY              LINKING
  (.c file)            (preprocessed)          (.s file)            (.o file)           (.out file)
 ┌───────────┐         ┌───────────┐         ┌───────────┐        ┌───────────┐        ┌───────────┐
 │           │         │           │         │           │        │           │        │           │
 │  #include │    1    │  (expanded│    2    │  assembly │   3    │  machine  │   4    │ executable│
 │  int main │ ───────>│   headers,│ ──────> │    code   │ ─────> │   code    │ ──────>│    file   │
 │  {        │         │   macros) │         │  (text)   │        │ (binary)  │        │           │
 │    ...    │         │           │         │           │        │           │        │           │
 └───────────┘         └───────────┘         └───────────┘        └───────────┘        └───────────┘
                                                                                            ▲
                                                                                            │
                                                            ┌───────────────────────────────┘
                                                            │
                                                       ┌────┴─────┐
                                                       │  Static  │
                                                       │ Libraries│
                                                       │  (.a/.o) │
                                                       └──────────┘
```

[[Precompiling]]

[[Compiling]]

[[Assembling]]

[[Linking]]

[[Common compilation errors]]
