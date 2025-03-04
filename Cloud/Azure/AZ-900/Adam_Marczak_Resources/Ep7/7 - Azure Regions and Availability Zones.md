
# Regions
![[Pasted image 20230825232940.png]]
- Geographical areas
- **One or more data centers** connected with **dedicated regional low-latency network (<2 milliseconds)**
- Location for our services/resources
- Special government regions + partnered regions

```ad-warning
Some services are available for **certain regions**, and some are global

```

# Availability Zones

![[Pasted image 20230910102312.png]]

- **Physically separate facilities** with independent cooling, power and networking infrastructure
- Connected via a **high-performance network with low-latency**
- Two service categories
	- Zonal services (VMs, Disks, etc.) => Allow customers to choose AZ to deploy their services
	- Zone-redundant services (SQL, Storage, etc.)
- Purposes:
	- Increase app resiliency and availability
	- Enable advanced scalability
	- Meet compliance and regulatory needs
	- Improve recovery time objectives (RTOs) and recovery point objectives (RPOs)
- Benefits:
	- Protection against infra disruptions
	- Ensure high availability + business continuity
	- Achieve scalability alongside with other services
	- Securely support solution needs

```ad-warning
Not all regions are supported

```

- Supported/Zone-enabled regions have **> three of more zones**
- A zone has **>1 data centers**

# Region Pairs
- Each region is paired with another region as Region pair
- Static + Cannot be chosen
- Each pair resides in the **same geography** (Except Brazil South)
- Physical isolation of 300 miles (when possible)
- **Some services** have **platform-provided replication**
- **Planned updates** across the pairs
- **Data residency** maintained for disaster recovery
- Fault tolerance

```ad-important
All Azure regions have a region pair and each region has **exactly one pair assigned**

```


# Geographies
- Discrete markets
- Have >2 regions
- Ensure **data residency, sovereignty, resiliency, and compliance** requirements are met
- Fault tolerant
- Areas: Americas, Europe, Asia Pacific, Middle East and Africa

```ad-important
Each region belongs to **only one Geography**

```
