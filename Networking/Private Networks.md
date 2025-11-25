Lots of places have a firewall that *hides the network from the rest of the world*.

The firewall *translates* internal IP addresses to external IP addresses using a process called **Network Address Translation** or NAT.

Two personal computers at home cannot share the same IP address, and each has its own private network with 24 million IP addresses.

Scenario: If I log into a remote computer, it tells me I'm logged in from (for example) `192.0.2.33` which is the public IP address from the ISP. When I ask my local computer what its IP address is, it could be `10.0.0.5`.

-> The firewall is doing its translation using NAT. `10.x.x.x` networks are reserved networks to be used for either on *fully disconnected networks* or *networks behind firewalls*.

Reserved networks are often `10.x.x.x` or `192.168.x.x`