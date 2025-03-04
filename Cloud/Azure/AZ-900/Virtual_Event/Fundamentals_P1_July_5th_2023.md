
# Architectural component
## Regions
- Datacenters in close proximity
- Provide flexibility
## Availability zones
- Provide protection against downtime
- Physically separate datacenters within the same region
- Each datacenter is equipped with independent resources e.g. cooling, VMs
- Connected via fiber-optic networks
## Region Pairs
- Automatic replication of **some** services
- Prioritize region recovery
- Roll out updates sequentially to reduce downtime

## Azure sovereign regions 
### US Government services
- Separate instance of Azure
- Isolated from non-US government deployments
- Accessible to authorized personnel 
### Azure China
- Instance governed by 21Vianet
- All data stays within China

## Azure resources
![[Pasted image 20230705154429.png]]

### Resource groups
- A resource group is a **container** to manage and aggregate resources **in a single unit**
- Resources can:
	- Only exist in 1 group
	- Exist in different regions
	- Be moved to different groups
- Applications can utilize **multiple** resource groups
- Resources Groups in Azure can represent a logical grouping of services
	- By their lifecycle
	- For billing and tracking purposes
	- By their resource type
	- By assigned departments
	- By geographical location

## Azure subscriptions
- Billing boundary
- Access control boundary

## Management groups
- Can include multiple subscriptions
- 10k management groups can be stored in a single directory
- Support six levels of depth
![[Pasted image 20230705155315.png]]

---
# Azure compute services
## Azure VMs
- IaaS offers this with total control and customization
### Scale sets
Scale sets provide a load-balanced opportunity to automatically scale resources (Scale in/out)

### Availability sets
- Organized into **Update domain** and **Fault domain** (TODO: Recheck)
	- Update domain: Updated/Rebooted when needed
	- Fault domain: Avoid complete failure with separate datacenters?
## Azure Virtual Desktops
Desktop and app virtualization running in the cloud

## Azure container services
- Light-weight, virtualized environment that **does not require OS management**
- Include **Azure container instances** and **Azure Kubernetes Service**
## Azure functions
- Event-based code running your service and not the underlying infra
## Azure App Services
- Fully managed platform to build, deploy, and scale web apps and APIs

## Azure Virtual Networks
- Enable Azure resources to communicate with each other
- What it provides
	- Public + private endpoints
	- Virtual subnets
	- Network peering

## Azure Virtual Private Network Gateway (VPN)
- Send encrypted traffic between Azure virtual network and on-premises location

## Azure ExpressRoute
- Extend on-premises networks into Azure over a private connection facilitated by a connectivity provider 
## Azure DNS

- Does **not** currently support DNSSEC