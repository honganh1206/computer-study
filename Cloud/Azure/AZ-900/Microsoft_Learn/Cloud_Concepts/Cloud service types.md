# IaaS

```ad-info
title: Definition
In an IaaS model, the cloud provider is responsible for maintaining 
- The hardware
- Network connectivity (to the internet)
- Physical security.


=> **You’re responsible for everything else**: operating system installation, configuration, and maintenance; network configuration; database and storage configuration; and so on.

```

## Shared responsibility model

- IaaS places the largest share of responsibility with you.
- While the cloud provider maintains the physical infra and its access to the internet, you are responsible for
	- Installation
	- Configuration
	- Patching and updates
	- Security
## Scenarios for IaaS

- Lift-and-shift migration: You can move the things running on-prem to cloud resources similar to your on-premise datacenter
- Testing and development: Stand up or shutdown different environments rapidly with IaaS structure while maintaining complete control

## Services

- Azure Storage Account
- Azure VMs


---
# PaaS

```ad-summary
title: Definition
Platform as a service (PaaS) is a middle ground between renting space in a datacenter (infrastructure as a service) and paying for a complete and deployed solution (software as a service)

```
## Shared responsibility model

- **Split the responsibility** between clients and the cloud provider
- The cloud provider is to maintain
	- Similar to IaaS
		- Physical infra
		- Physical security
		- Connection to the Internet
	- And also
		- OSes
		- Databases
		- Middleware
		- Development tools
		- Business intelligence services
- Depending on the configuration, either cloud consumers or providers are responsible for
	- Network settings and connectivity within the cloud environment
	- Network and application security
	- Directory infrastructure


```ad-tip
title: An advantage of PaaS
In a PaaS scenario, you don't have to worry about the licensing or patching for operating systems and databases.

```

## Scenarios

- Development framework
	- Create apps with built-in software components
	- Include cloud features e.g. scalability, high-availability, etc.
- Analytics/Business intelligence
	- Provide tools for orgs to analyze/mine their data to find patterns/predict outcomes/forecasting

## Services

- Azure Cache for Redis => Manage and scale Redis cache infrastructure
- Azure SQL database => Manage  and maintain database servers and infrastructure
- Azure Service Bus/Azure Queue Storage => Async messaging and decoupling
- Azure Cognitive Search => Managed search capabilities and indexing of structured + unstructured data
- Azure HDInsight => Managed Hadoop clusters for big data processing and analytics
- Azure App Service => Web application hosting

---
# SaaS

```ad-info
title: Definition
Software as a service (SaaS) is the most complete cloud service model from a product perspective. With SaaS, you’re essentially renting or using a fully developed application

```

## SRM

- **Nearly everything else falls to the cloud provider** => The cloud provider is responsible for physical security of the datacenters, power, network connectivity, and application development and patching.
- **Data + Connected devices + Users that have access** are the only aspects the cloud consumer is responsible for
- Licensed through a monthly/annual subscription
## Advantages

- Paying only for what you use
- Access to sophisticated software
- Mobilizing the workforce easily
- Access to data from any Internet-connected computer/device
- No need to develop apps for different types of computers/devices
- No need to manage data security on mobile devices => Data stored in service provider's data center
## Scenarios

- Email and messaging.
- Business productivity applications.
- Finance and expense tracking.