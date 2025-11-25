[[System call]]

## `getaddrinfo()`

```c
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int getaddrinfo(const char *node,   // e.g. "www.example.com" or IP
                const char *service,  // e.g. "http" or port number
                const struct addrinfo *hints,
                struct addrinfo **res); // (Result) Pointer to a linked list
                

// Sample call of getaddrinfo
int status;
struct addrinfo hints;
struct addrinfo *servinfo;  // will point to the results

memset(&hints, 0, sizeof hints); // make sure the struct is empty
hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
hints.ai_flags = AI_PASSIVE;     // fill in my IP (localhost) for me

if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
    fprintf(stderr, "gai error: %s\n", gai_strerror(status));
    exit(1);
}

// servinfo now points to a linked list of 1 or more
// struct addrinfos

// ... do everything until you don't need servinfo anymore ....

freeaddrinfo(servinfo); // free the linked-list
```

## `socket()`

Return a socket descriptor for later system calls

```c
#include <sys/types.h>
#include <sys/socket.h>

// IPv4 or Ipv6, stream or datagram, and TCP or UDP
int socket(int domain, int type, int protocol); 


// Use
int s;
struct addrinfo hints, *res;

// do the lookup
// [pretend we already filled out the "hints" struct]
getaddrinfo("www.example.com", "http", &hints, &res);

// again, you should do error-checking on getaddrinfo(), and walk
// the "res" linked list looking for valid entries instead of just
// assuming the first one is good (like many of these examples do).
// See the section on client/server for real examples.

s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
```

## `bind()`

Associate the socket with a port on the local machine. Common when we need to listen for incoming connections in a specific port.

```c
#include <sys/types.h>
#include <sys/socket.h>

int bind(int sockfd, struct sockaddr *my_addr, int addrlen);

struct addrinfo hints, *res;
int sockfd;

// first, load up address structs with getaddrinfo():

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

getaddrinfo(NULL, "3490", &hints, &res);

// make a socket:

sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

// bind it to the port we passed in to getaddrinfo():

bind(sockfd, res->ai_addr, res->ai_addrlen);

// Allow the program to reuse the port 
// from a socket previously hogging the port
int yes=1;
//char yes='1'; // Solaris people use this

// lose the pesky "Address already in use" error message
setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);
```

## `connect()`

Connect to a remote host

```c
#include <sys/types.h>
#include <sys/socket.h>

int connect(int sockfd, struct sockaddr *serv_addr, int addrlen); 

struct addrinfo hints, *res;
int sockfd;

// first, load up address structs with getaddrinfo():

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;

getaddrinfo("www.example.com", "3490", &hints, &res);

// make a socket:

sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

// No bind(). No need to care for local port number. We only care about the remote port, and the kernel will choose a local port for us.

// connect!

connect(sockfd, res->ai_addr, res->ai_addrlen);
```

## `listen()`

Wait for connections

```c
// Socket file descriptor + number of connections on the incoming queue (usually limit to 20)
int listen(int sockfd, int backlog); 

getaddrinfo();
socket();
bind();
listen();
/* accept() goes here */ 
```

## `accept()`

Handle the incoming connection in some way. Return a brand new socket descriptor used for this single connection, while the original one is still listening for more connections.

```c
#include <sys/types.h>
#include <sys/socket.h>
 // Params from left to right:
 // sockfd: Socket descriptor that is doing the listening()
 // *addr: Pointer to a local struct sockaddr_storage (where information about the incoming connection will go)
 // *addrlen: Size of sockaddr_storage
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen); 

// How it works:

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

getaddrinfo(NULL, MYPORT, &hints, &res);

// make a socket, bind it, and listen on it:
sockfd = socket(res->ai_family, res->ai_socktype,
											 res->ai_protocol);
bind(sockfd, res->ai_addr, res->ai_addrlen);
listen(sockfd, BACKLOG);

// now accept an incoming connection:

addr_size = sizeof their_addr;
new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
												   &addr_size);
```

## `send()` and `recv()`

The two functions communicate over stream sockets or connected data sockets.

```c
int send(int sockfd, const void *msg, int len, int flags); 

// Socket descriptor to read from, buffer to read the information to, len for buffer's length, and flags can be set to 0
int recv(int sockfd, void *buf, int len, int flags);
```

> [!important]
> Both `send()` and `recv()` are blocking calls (See [[Waiting, Blocking and Reaping]] and the analogy of channels in [[Channels]] in Go). TLDR: Our program is going to stop there, on that system call, until someone sends you something. 

```c
char *msg = "Beej was here!";
int len, bytes_sent;
.
.
.
len = strlen(msg);
// Return the number of byts ACTUALLY sent
// sometimes bytes_sent < len, so we need to re-send the rest of the string
bytes_sent = send(sockfd, msg, len, 0);
```