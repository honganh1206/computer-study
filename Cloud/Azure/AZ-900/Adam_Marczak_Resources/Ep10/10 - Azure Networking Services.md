
# Azure Virtual Network (VN)

![[Pasted image 20230910222717.png]]

- Emulate **physical networking infra**
- Designed for **isolation + segmentation + communication + filtering + routing** between resources (internet and on-premises)
- Scoped to a **single region**
- **VNet Peering** or **VPN Gateway** allow **cross VNet communication**
- Segmented into >1 subnets
- Subnets are **discrete sections** used for
	- Effective **address allocation**
	- **Network filtering** via **Network Security Groups (NSG)** or **Application Security Groups (ASG)**

# Network Security Group (NSG)

![[Pasted image 20230910224209.png]]


# Virtual Network Gateway

![[Pasted image 20230915154817.png]]

- **On-premises to Azure** traffic over the public internet
- **Cross-regional communication** of Azure VNs

```ad-note
VNet peering vs. VPN Gateway should be chosen **based on organization needs**

```

# Azure Load Balancer
## Improve SLA by putting VMs into separate AZ

![[Pasted image 20230915155205.png]]

## Separate resources into tiers

![[Pasted image 20230915162102.png]]

- **Even** traffic distribution
- Support both inbound and outbound scenarios
- High-availability and scalability scenarios
- Support both TCP (transmission control protocol) and UDP (user datagram protocol) applications
- External and internal traffic

# Application Gateway

![[Pasted image 20230915163226.png]]

- Web traffic load balancer
- Web application firewall
- Redirection
- Session affinity (Ensure users are redirected )
- URL Routing
- SSL termination

![[Pasted image 20230915163655.png]]


# Content Delivery Network

![[Pasted image 20230915164119.png]]

- Deliver web content to users near **POP** (points of presence) locations
- Minimize latency