Processes with private virtual address spaces can send/receive messages to/from each other.

Message passing allows programs to *exchange arbitrary data* rather than just a small set of predefined messages like those supported by [[Signal]]

## Communication model

1. Processes allocate some type of message channel from the OS. Example types include [[Pipes]] for one-way communication, and [[Sockets]] for two-way communication. Additional connection setup steps might follow.
2. Processes use the message channel to send and receive messages.
3. Processes close their end of the message channel when they are done using it.

Since each computer is its own system (hardware and OS), and because the OS does not know about or manage resources on the other system, message passing is the only way processes on different computers can communicate. For that reason, OSes need to implement a common message passing protocol like TCP/IP.

There are different system software abstractions built on top of message passing, and they hide the message passing details from the programmer.

> [!important]
> Any communication between processes on different computers must use message passing at the lowest levels (signals and message passing and shared memory are not an option).