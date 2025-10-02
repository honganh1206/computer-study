A *two-way communication channel*, meaning each end can be used for sending and receiving messages.

Sockets can be used by processes on the same computer or computers connected by a framework. The computers could be connected by a *local area network* (LAN), and the communicating processes could also be on different LANs.

![[image-25.png|Sockets as bidirectional communication channels]]

When a process wants to send a message, it makes a `send` system call, which passes the OS a socket on which it wants to transmit + the message buffer + information about the message/intended recipient.

The sending OS packs up the message in the buffer and sends it over the network to the other machine. An OS on the receiving machine unpacks the message and delivers it to the process on its system.

> During the wait to receive messages, the receiving process may be in a Blocked state.