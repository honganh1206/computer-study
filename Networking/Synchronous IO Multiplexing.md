
## `poll()`

What we need to do: Monitor a bunch of sockets at once, then handle the ones that have the data ready.

> [!warning]
> `poll()` is horribly slow when dealing with a lot of connections. 

We use `poll()` to avoid polling (yes, it is). We let the OS do the dirty work and let us know, and while the OS is doing so, *our process can go to sleep to save resources*.

General idea: Keep an array of `struct pollfd` with information about which socket descriptors we want to monitor + what kind of event we want to monitor. The OS will block on `poll()` call until one of those events occurs.

```c
#include <poll.h>

struct pollfd {
    int fd;         // the socket descriptor
    short events;   // bitmap of events we're interested in
    short revents;  // on return, bitmap of events that occurred
};
// array of sockets to monitor, number of sockets, and timeout obviously
int poll(struct pollfd fds[], nfds_t nfds, int timeout);
```

`events` field is the bitwise-OR of the following

| Macro     | Description                                                        |
| --------- | ------------------------------------------------------------------ |
| `POLLIN`  | Alert me when data is ready to `recv()` on this socket.            |
| `POLLOUT` | Alert me when I can `send()` data to this socket without blocking. |
| `POLLHUP` | Alert me when the remote closed the connection.                    |

## `select()`

Scenario: You are a server. You want to listen for incoming connections, as well as reading from the connections you already have.

`poll()` is good but it has its own problems: 

1. `accept()` blocks if there is no connection 
2. We cannot use a non-blocking socket which will lead to CPU hogging. 
3. We cannot use `recv()` to receive data at the same time.


We then use `select()`, which is based on the logic of a [[Multiplexer]], to *monitor several sockets at the same time* and tell which one is ready for which task.

`select()` will does nothing until: (1) A client sends data, (2) A connection arrives or (3) Something goes wrong.

```c
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Each set is of type fd_set
// To read from the standard input or a sockfd, add them to readfds
// and remember to set them as sockfd+1
int select(int numfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout); 
           

struct timeval {
    int tv_sec;     // seconds
    int tv_usec;    // microseconds
};
```


Macros to manipulate `fd_set` typed variables:

| Function                         | Description                          |
| -------------------------------- | ------------------------------------ |
| `FD_SET(int fd, fd_set *set);`   | Add `fd` to the `set`.               |
| `FD_CLR(int fd, fd_set *set);`   | Remove `fd` from the `set`.          |
| `FD_ISSET(int fd, fd_set *set);` | Return true if `fd` is in the `set`. |
| `FD_ZERO(fd_set *set);`          | Clear all entries from the `set`.    |

