## IPv4

IPv4 has addresses made up of four bytes/octets e.g., 192.0.2.111. We are talking about 4 billion addresses ($2^{32}$).

Virtually every site on the Internet uses IPv4.

Problem: We re running out of IPv4 addresses, so that's why IPv6 was born.

## IPv6

IPv6 means we have 8 bytes, and for that we use hexadecimal representation like `2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551`. Each two-byte chunk is separated by a colon.

We can leave off the leading zeros for brevity:

```
2001:0db8:c9d2:0012:0000:0000:0000:0051
2001:db8:c9d2:12::51

2001:0db8:ab00:0000:0000:0000:0000:0000
2001:db8:ab00::

0000:0000:0000:0000:0000:0000:0000:0001
// Loopback address a.k.a this machine I'm running on now a.k.a localhost
::1
```

With IPv6, we are talking about $2^{128}$ addresses, and that's like *a million IPv4 Internets for every single star in the universe*.

IPv6 is also IPv4-compatible, meaning we can represent an IPv4 address as follow:

```
// IPv4
192.0.2.33
// IPv6
::ffff:192.0.2.33
```

[[Subnets]]

[[Port Numbers]]

[[Byte Order]]

[[Structs and functions for Networking in C from standard libs]]
