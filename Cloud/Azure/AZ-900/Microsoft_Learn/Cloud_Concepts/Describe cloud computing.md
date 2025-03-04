# Cloud computing
- No constraint from physical infrastructure as a traditional datacenter has
# Shared responsibility model
- Responsibilities are shared between cloud provider and consumers
	- Consumer: Data privacy/integrity 
		- Info stored on cloud
		- Connected devices
		- Accounts/Identities
	- Cloud provider: Physical security, power, cooling, and network connectivity

## Cloud service types
- Infrastructure as a service (IaaS) (Most responsibility on consumers)
- Platform as a service (PaaS)
- Software as a service (SaaS) (Least responsibility on consumers)

![[Pasted image 20230628212751.png]]

- Responsibilities of the service model
	- Operating systems
	- Network controls
	- Applications
	- Identity and infrastructure

---
# Cloud models

| Types         | Benefits                                                                                                              | Downsides                         |
| ------------- | --------------------------------------------------------------------------------------------------------------------- | --------------------------------- |
| Private cloud | - Greater control </br> - Hosted in a dedicated datacenter offsite </br> - Minimize capital + operational expenditure | - Great cost for self-maintenance | 
| Public cloud  | - Anyone who wants to purchase cloud services can access + use resources </br> - Pay for what to use only             | - Little control                  |
| Hybrid cloud  | - Flexibility (Services are for single customers + anyone who wants to purchase)                                      |                                   |

- Multi-cloud == Multiple public cloud providers (Azure/AWS/Google cloud)

## Azure VMware Solution
- Run VMware workloads in Azure


---
# Operating models

## Consumption-based model

- Types of expenses
	- Capital expenditure (**CapEx**) - One-time, up-front expenditure
	- (**Cloud computing focuses on this**) Operational expenditure (OpEx) - Spending money on services over time
- Challenges:
	- **Less efficient for estimating baseline costs** when:
		- There are predictable spikes in usage
		- Utilizing PaaS and serverless technologies, as the costs can vary based on demand and usage patterns.
		- Using PaaS and serverless technologies
	- **Challenging** to implement in multitenant solutions due to 
		- The need for **accurate measurement of usage** 
		- The complexity of splitting usage by tenant.
- Factors to consider:
	- Fluctuations in usage patterns
	- Baseline costs
	- Cost of goods sold (COGS) vs. profit

```ad-info
title: Cloud operating model vs. Traditional IT operating model
- Cloud OM prioritizes **server uptime** and **hardware refreshes**
- Cloud OM helps **reduce constraints** and **think about new ways of operating**
- Cloud OM DOES NOT require different people and processes compared to traditional IT operating model
```

## Per-active user vs . Per-user pricing models

- Per-active user pricing models have a **less predictable** revenue stream compared to per-user pricing models as **the number of active users can vary**.

## Cost of goods sold (COGS) pricing model

- Charge customers based on the cost of operating their share of Azure services

## Factors to consider regarding pricing models

- Implementing rate limits
	- Preventing overuse of resources by tenants
	- Protecting core components from performance issues
	- Increasing complexity and operational cost

```ad-warning
Updating the operating model for cloud adoption **DOES NOT** remove the need for procurement, change management, and operations.

```


---
# [Confidential Computing](https://learn.microsoft.com/en-us/azure/confidential-computing/overview)

- The protection of data in use by **performing computation in a hardware-based**, attested Trusted Execution Environment (TEE).
- Scenarios:
	- Secure multi-party computation
	- Anti-money laundering
	- Drug development in healthcare
	- Protecting privacy with IoT and smart-building solutions
	- Addressing legal or jurisdictional requirements.
- Benefits 
	- Enhance customer data privacy
		- Technical enforcement of security measures
		- Transparency about guarantees and mitigations
		- Retained control over secrets and Trusted Computing Base (TCB)
	- Blockchain networks
		- Data confidentiality + Secure computations
		- Encryption of the entire ledger

---
# Security governance

- Aligns business priorities with technical implementation by **establishing architecture, standards, and policies to ensure security**. (**NOTE**: This applies to both traditional IT and cloud operating models)
- Key components:
	- Compliance and reporting
	- Architecture and standards
	- Security posture management
	- Continuous improvement