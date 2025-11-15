Processes in a distributed memory system communicate via **message passing**, whereby one process explicitly sends a message to processes on one or more other nodes, which receives it.

A distributed application formalizes its communication expectations by defining a *communication protocol*, which describes a set of rules that govern its use of the network:

- When a process should send a message
- Which process should receive the message
- How to format the message

To do so, applications require some functionalities like:

- Sending/receiving messages
- Naming processes (Addressing)
- Synchronizing process execution

[[Message Passing Interface]]