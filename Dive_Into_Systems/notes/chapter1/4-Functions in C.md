---
id: 4-Functions in C
aliases:
  - 4-Functions in C
tags: []
---

# 4-Functions in C

All functions in C must be declarted before they are called (Well, obviously!)

Arguments in C functions are **passed by value**: Each function parameter is **assigned** the value of the corresponding argument passed to it.

C uses **function prototypes**: Kinda like interface, as they allow `main` to call the function before its full definition appears int he file

## The Stack

**TLDR**: Just like how a stack works

The **execution stack** keeps track of the _state of active functions_ in a program

Each function call creates a new **stack frame/activation frame/activation record** containing its parameter and local variable

The frame on the top is the **active frame**

When a function is called, a new stack frame is created for it aka **pushed** on the top of the stack and space for its local variable s and parameters is allocated

When a function returns, its stack frame is removed from the stack akai **popped** from the top of the stack

    +-----------------+
    |      max:       |
    +-----------------+
    |  x:     [ 100 ] |
    |  y:     [ 100 ] |
    |  bigger:[ 100 ] |
    +-----------------+
    |      main:      |
    +-----------------+
    |  a:     [  13 ] |
    |  b:     [ 100 ] |
    |  res:   [   ?  ]|
    +-----------------+

                 Stack
