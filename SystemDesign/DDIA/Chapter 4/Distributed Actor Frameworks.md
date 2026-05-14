The **actor model** is a programming model for *concurrency in a single process*.

Instead of dealing directly with threads (why a bad thing?) logic is encapsulated in actors. Actors have local state and communicate with other actors by sending/receiving asynchronous messages.

Message can be lost in certain scenarios. Each actor can process one message at a time, and actor can be scheduled independently by the framework.

In distributed actor frameworks (used to scale application across multiple nodes), the same message-passing mechanism is used when senders/receivers are on the same node. On different nodes, messages are encoded into a byte sequence and sent over the network, and later decoded.

A distributed actor framework = A message broker + Actor programming model


