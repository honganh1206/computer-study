A way to speak to other programs using standard Unix [[File descriptor]] (integers associated with an open file).

> Everything in Unix is a file. That file can be a network connection, a FIFO, a pipe, a terminal, a real on-the-disk file, or anything else.

When we open a network socket, that socket is also represented by an integer and it is called **socket descriptor**.

We call to the `socket()` system routine, and we communicate through it using the specialized `send()` and `recv()` socket calls (Like [[Message Passing Interface]]?)

There all all kinds of sockets: Internet sockets, Unix sockets, etc.

## Internet sockets

Two types: Stream sockets `SOCK_STREAM` (reliable and orderly) and Datagram sockets `SOCK_DGRAM` or "connection-less sockets"

### Stream sockets

Used for telnet or ssh applications and HTTP to get pages, and they are **error-free**

Stream sockets use the "Transmission Control Protocol" or TCP - making data arrive sequentially and error-free

Good for chat messages with order and safety when delivering

### Datagram sockets

More unreliable. They may arrive, and they might arrive out of order, and the data within the packet will be error-free.

Datagram sockets use the "User Datagram Protocol" or UDP

Build a packet, slap an IP header on it with destination information, and send it out. No connection needed. Used when TCP is not available

Good for fire-and-forget scenarios where speed matters.

