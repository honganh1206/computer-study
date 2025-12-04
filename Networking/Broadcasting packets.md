We can send data to multiple hosts at the same time by setting `SO_BROADCAST`.

IPv4 supports broadcasting while IPv6 doesn't, so we have to resort to multicasting for the latter.

When a system receives a broadcast packet, it must undo all the layers of [[Data encapsulation]] until it finds out what port the data is destined to. That's a lot of work for each machine, so we need to *specify the destination address for a broadcast message*.

Two ways to do this:

1. Send the data to a specific subnet's broadcast address. Supposed our network is `192.168.1.0` and our netmask is `255.255.255.0`, our broadcast network is `network_number OR (NOT netmask) = 192.168.1.255`
2. Send the data to the global? broadcast address a.k.a `255.255.255.255`. Many machines will automatically bitwise AND this with your network number to make a network broadcast message, but *some won't*

> [!warning]
> Be careful with broadcast packets, since every machine on the LAN will be *forced to deal with the packet* even though it does not call `recvfrom()`.