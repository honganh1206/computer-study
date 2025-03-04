# Azure Virtual Networking

- An extension of your on-premises network with resources that link other Azure resources
- Capabilities
	- Isolation and segmentation
	- Communicate between Azure resources
	- Communicate with on-premises resources
	- Route network traffic
	- Filter network traffic
	- Connect virtual networks
- Support both public/private endpoints for communication between external and internal resources

## Isolation and segmentation - Create multiple isolated virtual networks

## Internet communications

## Communicate between Azure resources

- Virtual networks
- Service endpoints
	- Connect Azure resources to Azure virtual networks

## Communicate with on-premises resources

- Point-to-site private connections: The client computer (outside your organization) initiates an encrypted VPN connection to the Azure virtual network
- Site-to-site: Link your on-premises VPM device/gateway to the **Azure VPN gateway** => The devices in Azure can appear as being on the local network
- ExpressRoute: Provide a dedicated private connectivity to Azure that **does not travel over the internet** => Greater bandwidth and security

![[Pasted image 20230720105711.png]]


```ad-warning
- ExpressRoute provides private connectivity, but it is NOT encrypted.
- **Inbound data to Azure is always free, but outbound data from Azure is charged** via ExpressRoute, VPNs, direct connection to Azure, etc.
- Data transfers between Azure services *located within the same region* are **NOT** charged/**free**.
```

## Route network traffic

- Route tables allow you to **define rules about how traffic should be directed**
- Border Gateway Protocol (BGP) works with Azure VPN gateways, Azure Route Server, or Azure ExpressRoute to **propagate on-premises BGP routes to Azure virtual networks**.

## Filter network traffic 

Filter traffic between subnets:
- Network security groups: Azure resources that can contain **multiple inbound (free) and outbound (charged) security rules**
- Network virtual appliances: Specialized VMs that can be compared to a hardened network appliance

```ad-note
title: Azure Window Server and VMs
All outbound traffic sent from Azure Windows server Virtual Machines (VM) is encrypted by default.

```


```ad-warning
Subnets CANNOT be nested

```

## Connect virtual networks using Virtual Network Peering

- Network traffic between peered networks is private
- User-defined routes (UDRs) allow you to control routing tables between subnets **within a virtual network or between virtual networks**

---
# Exercise: Configure network access
## Access your web server

- Store IP address of the VM
```bash
IPADDRESS="$(az vm list-ip-addresses \
  --resource-group [resource group name] \
  --name my-vm \
  --query "[].virtualMachine.network.publicIpAddresses[*].ipAddress" \
  --output tsv)"
```
- List network security groups associated with the resource group
```bash
az network nsg list \
  --resource-group [resource group name] \
  --query '[].name' \
  --output tsv
```
- List the rules associated with the network security group (NSG)
```bash
az network nsg rule list \
  --resource-group [resource group name] \
  --nsg-name [NSG name]
```
- Create a rule (Allow http)
```bash
az network nsg rule create \
  --resource-group resource-group-name \
  --nsg-name nsg-name-here \
  --name allow-http \
  --protocol tcp \
  --priority 100 \
  --destination-port-range 80 \
  --access Allow
```

---
# Azure Virtual Private Networks
## VPN Gateways
- Azure VPN Gateway instances can enable the following activities:
	- Connect on-premises datacenters to virtual networks (Site-to-site)
	- Connect individual devices to virtual networks (Point to site)
	- Connect virtual networks to other virtual networks (Network-to-network)

![[Pasted image 20230720105328.png]]

```ad-attention
You can only deploy **only one VPN gateway** in each virtual network, but you can use one gateway to connect to multiple locations

```

### VPN types

| Policy-based                                                                                                                                                 | Route-based                                                                                                                                                                      |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| - Specify statically the IP address of packets encrypted through each tunnel </br> - Evaluate every data packet against those sets of IP addresses to choose | Use this for </br> - Connections between virtual networks </br> - Point-to-point connections </br> - Multi-site connections </br> - Co-existence with Azure ExpressRoute gateway |
|                                                                                                                                                              |                                                                                                                                                                                  |
## High-availability scenarios

---
# Azure ExpressRoute

- Extend on-premises networks into the Microsoft cloud over a private connection with the help of a connectivity provider - **ExpressRoute Circuit** - to establish connections to Microsoft cloud services
- ExpressRoute connections do not go over the public Internet => Guarantee reliability/faster speeds/consistent latencies/higher security

```ad-warning
ExpressRoute provides private connectivity, but it is **NOT** encrypted.

```

## Features

- Global connectivity
- Dynamic routing
- Built-in redundancy
## ExpressRoute connectivity models

- CloudExchange co-location
- Point-to-point Ethernet connection
- Any-to-any connection
- Directly from ExpressRoute sites

---
# Azure DNS

- A hosting service for DNS domains that **provides name resolution** by using Microsoft Azure infrastructure.
## Benefits of using Azure DNS

- Reliability and performance
- Security
- Ease of Use
- Customizable virtual networks
- Alias records

---
# Azure Load Balancer & Application Gateway

- ALB: Distribute non-HTTP/non-web traffic evenly across multiple backend services in the server pool
- AG: Distribute HTTP/web traffic evenly across multiple backend service

---
# Azure Content Delivery Network (CDN)

- **Cache** and **distribute** web application content across multiple points of presence (POP) locations => Minimize latency of delivery to customers

---

# [Azure Firewall](https://learn.microsoft.com/en-us/azure/firewall/overview)

- Limit the amount of **inbound traffic** => Used in combination with Azure Application Gateway for both **web and non-web workloads**

---
# [Azure Front Door](https://learn.microsoft.com/en-us/azure/frontdoor/front-door-overview)

- Manage traffic from and to applications (similar to Load Balancer)
- Can be used for securing **web workloads**

```ad-info
Secure unused publishing methods for application resources by **disabling all publishing methods except SCM for Azure Web Apps**

```

```ad-todo
title: Handle service disruptions in Azure VMs


```

---
# Azure Private Link

- Access Azure PaaS services over private endpoints
---
# [Best practices for endpoint security](https://learn.microsoft.com/en-us/azure/well-architected/security/design-network-endpoints)

- **Protect all public endpoints** with Azure Front Door, Application Gateway, Azure Firewall, Azure DDoS Protection.
- Use **web application firewall** (WAF) to protect web workloads.
- **Protect workload publishing methods** and **restrict ways** that are not in use.
- **Mitigate DDoS attacks**. Use Standard protection for critical workloads where outage would have business impact. Also consider CDN as another layer of protection.
- **Develop processes and procedures to prevent direct internet access of virtual machines** (such as proxy or firewall) with logging and monitoring to enforce policies.
- Implement an **automated and gated CI/CD** deployment process.

---
# [Network Watcher](https://learn.microsoft.com/en-us/azure/network-watcher/network-watcher-overview)

- Provides **a suite of tools to monitor, diagnose, view metrics, and enable or disable logs** for Azure IaaS (Infrastructure-as-a-Service) resources.
- Enables you to **monitor** and **repair** the network health of IaaS products like virtual machines (VMs), virtual networks (VNets), application gateways, load balancers, etc.