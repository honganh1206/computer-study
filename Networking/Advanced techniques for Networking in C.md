## Blocking

[[Waiting, Blocking and Reaping]]

Think of block as a techie jargon for *sleep*. 

When we use `recvfrom()` to wait for a datagram packet to arrive, and if there is no data, the `recvfrom()` will block/sleep the code until some data arrives.

If we don't want a socket to be blocking, we have to make a call to `fcntll()`:

```c
#include <unistd.h>
#include <fcntl.h>
.
.
.
sockfd = socket(PF_INET, SOCK_STREAM, 0);
// set the socket to non-blocking
fcntl(sockfd, F_SETFL, O_NONBLOCK);
.
.
. 
```

We can then *poll* the socket for information.

If we try to read from a non-blocking socket, it will return -1 and `errno` will be set to either `EAGAIN` or `EWOULDBLOCK` (But we don't know what to check for + suck up CPU resource, so using polling like this is a bad idea in general)

[[Synchronous IO Multiplexing]]

[[Data packing]]

[[Data encapsulation]]

[[Broadcasting packets]]



