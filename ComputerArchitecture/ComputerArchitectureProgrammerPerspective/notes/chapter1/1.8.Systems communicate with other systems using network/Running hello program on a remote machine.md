---
tags:
  - "#study"
cssclasses:
  - center-images
---
![[{50193036-D937-48BC-BBA9-6DAB5A924370}.png]]

Scenario: We use the telnet application to run `hello` on a remote machine. We have a telnet client on the local + telnet server on the remote one.

=> After we log in to the remote machine and run a shell, the remote shell is *waiting to receive an input command*.

The steps:

1. We type “hello” at the keyboard
2. Client sends the “hello” string to telnet server
3. The string is passed to the remote shell program on the telnet server
4. The remote shell runs the `hello` program and passes the output to the telnet server
5. The telnet server forwards the output to the telnet client
6. The output is printed on the local terminal

More on [[Chapter 11]]