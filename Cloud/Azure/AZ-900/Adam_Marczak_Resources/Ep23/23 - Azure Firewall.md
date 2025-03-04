
```ad-abstract
title: Firewall
A network security device that **monitors** and **controls incoming and outgoing traffic**

```

![[Pasted image 20231001105656.png]]

- Managed, cloud-based firewall service (PaaS, Firewall as a Service)
- Built-in high availability
- Highly scalable 
- Inbound & Outbound traffic filtering rules
- Support for **Fully Qualified Domain Name** (FQDN) e.g. microsoft.com
- **Fully integrated** with Azure monitor for logging and analytics

```ad-attention
When provisioned, Azure Firewall will **block all traffic** because the default rule is set to 'deny' => A rule has to be added to enable traffic flow

```
