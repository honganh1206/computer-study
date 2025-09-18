A software interrupt the OS delivers to a process. It is a way processes communicate with each other.

When a process receives a signal, it is interrupted to *run a special signal handler code*.

A system defines a *fixed* number of signals, with each differentiated by a unique signal number.

The OS implement default signal handlers, but programmers can register their own user-level signal handler code to override the default actions.

