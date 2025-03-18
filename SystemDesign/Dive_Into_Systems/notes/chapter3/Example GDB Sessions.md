---
id: Example GDB Sessions
aliases:
  - Example GDB Sessions
tags: []
---

# Example GDB Sessions

| Command | Description                                                                                                                   |
| ------- | ----------------------------------------------------------------------------------------------------------------------------- |
| `break` | Set a breakpoint                                                                                                              |
| `run`   | Start a program running from the beginning                                                                                    |
| `cont`  | Continue execution of the program until it hits a breakpoint                                                                  |
| `quit`  | Quit the GDB session                                                                                                          |
| `next`  | Allow program to execute the next line of C code and then pause it                                                            |
| `step`  | Allow program to execute the next line of C code; if the next line contains a function call, step into the function and pause |
| `list`  | List C source code around pause point or specified point                                                                      |
| `print` | Print out the value of a program variable (or expression)                                                                     |
| `where` | Print the call stack                                                                                                          |
| `frame` | Move into the context of a specific stack frame                                                                               |

```bash
# set breakpoint at the start of main()
(gdb) break <function_name> / <line_number>
# Run command
(gdb) run
# With arguments
(gdb) run <arg_1> <arg_2>
# Display the code surrounding the breakpoint
(gdb) list
# Show the code around the specific line number or function name
(gdb) list <function_name> / <line_number>
# Step into the invoked function
(gdb) step
# Tell GDB to let the application's execution continue from a paused point
(gdb) cont
# Tell GDB to automatically print out the set of variables everytime the breakpoint is hit
(gdb) display <identifier>
# Examine the content of the stack call
(gdb) where
# Move to the context of any frame
(gdb) frame <number>
```
