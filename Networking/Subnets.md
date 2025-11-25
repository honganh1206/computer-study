For organizational reasons, it is determined that the first part of a specific IP address up through a bit is the *network portion* and the remainder is the *host portion*.

Example: The three first bytes of `192.0.2.12` are the network (`192.0.2`) and the last byte `12` is the host. 

Class A network means we have 3 bytes/24 bits worth of hosts on our network, and class C means 1 byte for the network.

## Netmask

Describe the network portion of IP addresses. The netmask sets certain bits to 1 (network) and the remaining bits to 0 (hosts)

We do bitwise-AND with the IP address to get the network number out of it

Example: We have netmask `255.255.255.0` (first 24 bits belong to the network, remaining 8 bits for host so this is the `/24` subnet) and if our IP is `192.0.2.12`, our network will be `192.0.2.12 AND 255.255.255.0 = 192.0.2.0` and there will be $2^{8} = 256$ hosts.

## The Powers That Be

TPTB allows the netmask to be an *arbitrary number* of bits, not just 8, 16 or 24

So we might have a netmask of `255.255.255.252` or `/30` (30 bits of network, 2 bits of host allowing $2^{2}=4$  hosts)

```css
255  = 11111111
255  = 11111111
255  = 11111111
252  = 11111100
```

 For IPv6, it will be something like `2001:db8::/32` or `2001:db8:5413:4028::9db9/64`