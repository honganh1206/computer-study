## Structs
 
```c
struct addrinfo {
	int ai_flags; // AI_PASSIVE, AI_CANONNAME, etc.
	int ai_family; // AF_INET (IPv4), AF_INET6 (IPv6), AF_UNSPEC
	int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
	int ai_protocol; // use 0 for "any"
	size_t ai_addrlen; // size of ai_addr in bytes
	struct sockaddr *ai_addr; // struct sockaddr_in or _in6
	char *ai_canonname; // full canonical hostname
	struct addrinfo *ai_next;
};
```

Prepare socket address structures. We call `getaddrinfo()` which returns a pointer to a new linked list of these structures.

```c
struct sockaddr {
	unsigned short sa_family; // address family, AF_xxx
	char sa_data[14]; // 14 bytes of protocol address
}
```

`sa_family` can be either `AF_INET` (IPv4) or `AF_INET6` (IPv6). `sa_data` contains a destination address and port number for the socket.

We handle `struct sockaddr` with *parallel structures* like `struct sockaddr_in` (`in` stands for "Internet") used with IPv4

```c
// (IPv4 only--see struct sockaddr_in6 for IPv6)
struct sockaddr_in {
	short int sin_family; // Address family, AF_INET
	unsigned short int sin_port; // Port number (must be Network Byte Order)
	struct in_addr sin_addr; // Internet address
	unsigned char sin_zero[8]; // To pad to the size as struct sockaddr
};

// Internet address (a structure for historical reasons)
struct in_addr {
	uint32_t s_addr; // that's a 32-bit int (4 bytes)
};
```

> A pointer to a `struct sockaddr_in` can be cast to a pointer to a `struct sockaddr` and vice versa.

```c
// (IPv6 only--see struct sockaddr_in and struct in_addr for IPv4)
struct sockaddr_in6 {
	u_int16_t sin6_family; // address family, AF_INET6
	u_int16_t sin6_port; // port number, Network Byte Order
	u_int32_t sin6_flowinfo; // IPv6 flow information
	struct in6_addr sin6_addr; // IPv6 address
	u_int32_t sin6_scope_id; // Scope ID
};

struct in6_addr {
	unsigned char s6_addr[16]; // IPv6 address
};
```

Another parallel structure for when we don't know whether to full out `struct sockaddr` with IPv4 or IPv6 address:

```c
struct sockaddr_storage {
	sa_family_t ss_family; // address family
	
	// all this is padding, implementation specific, ignore it:
	char __ss_pad1[_SS_PAD1SIZE];
	int64_t __ss_align;
	char __ss_pad2[_SS_PAD2SIZE];
};
```

## Functions

 Supposed we have an IP address, and we want to convert it into either `struct in_addr` or `struct in6_addr`, we might want to use `inet_pton()` (presentation to network) function

```c
// Convert string IP addresses to their binary representations
struct sockaddr_in sa; // IPv4
struct sockaddr_in6 sa6; // IPv6
inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr)); // IPv4
inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6

```

The other way around: Convert binary representations to string IP addresses with `inet_ntop()` (network to presentation)

```c
// IPv4:

char ip4[INET_ADDRSTRLEN];  // space to hold the IPv4 string
struct sockaddr_in sa;      // pretend this is loaded with something

// Pass address type, the address itself, a pointer to a string to hold the result, and the maximum length of that string (macros)
inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

printf("The IPv4 address is: %s\n", ip4);


// IPv6:

char ip6[INET6_ADDRSTRLEN]; // space to hold the IPv6 string
struct sockaddr_in6 sa6;    // pretend this is loaded with something

inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);

printf("The address is: %s\n", ip6);
```

> [!warning]
> These functions only work with numeric IP addresses, and they won't do any nameserver DNS lookup on a hostname like `www.example.com`

For datagram, we use `sendto()` and `recvfrom()`

```c
// Since datagram sockets are not connected to remote host,
// we need to specify the destination address
// and tolen specifies size of *to
int sendto(int sockfd, const void *msg, int len, unsigned int flags,
           const struct sockaddr *to, socklen_t tolen); 

// from is a pointer to a local struct sockaddr_storage
// and that will be filled with the IP address + port from originating machine
// and fromlen specifies the length of *from
int recvfrom(int sockfd, void *buf, int len, unsigned int flags,
             struct sockaddr *from, int *fromlen); 
```

> If we do `connect()` to a datagram socket, we still can use `send()` and `recv()`, and the socket interface will fill out the destination and source information for us.

## `close()` and `shutdown()`

```c
// Prevent reads and writes to the socket
close(sockfd); 

// Cut off communication in a certain direction (0 for receive, 1 for send, 2 for both like close() does it)
int shutdown(int sockfd, int how); 
```

## `getpeername()` and `gethostname()`

```c
#include <sys/socket.h>

// Tell the person at the other end of a connected stream socket
int getpeername(int sockfd, struct sockaddr *addr, int *addrlen); 

#include <unistd.h>

// Return the name of the computer the programming is running on
int gethostname(char *hostname, size_t size); 
```