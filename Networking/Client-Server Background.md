When we connect to a remote host on port 23 with `telnet` (the client), a program on that host (`telnetd` - the server) springs to life to handle the incoming telnet connection.

The client-server pair can speak `SOCK_STREAM` or `SOCK_DGRAM` or anything else as long as they are speaking the same thing.

One server on a machine can handle multiple clients using `fork()` (spawn child processes to handle a connection)