# Physical infrastructure

- Datacenters are grouped in **Azure Regions** or **Azure Availability Zones**
## Availability Zones

- Grouping of **physically separate facilities**
- Designed to **protect from data center failures**
- If 1 zone goes down => Others continue working

```ad-warning
- Not all regions are supported with availability zones
```

- A zone consists of **one or more data centers**
### Use availability zones in your apps
Azure services that support availability zones fall into three categories:
- Zonal services - Pin the resource to **a specific zone**
- Zone-redundant services - The platform **replicates automatically across zones**
- Non-regional services

```ad-note
Zone enabled regions must have **a minimum of three (3) availability zones**

```

## Region pairs

- Most Azure regions are paired with another region within the same geography (such as US, Europe, or Asia) at least 300 miles away => Reduce the likelihood of interruptions
- Advantages
	- One region out of every pair is prioritized to make sure one is restored ASAP
	- Roll out updates to one of every pair to minimize downtime/risk of outage
	- Data resides within the same geography for tax- and law-enforcement purposes
	- Reduce the likelihood of natural disasters affecting both regions

---
# Management infrastructure

```ad-important
title: Choosing the right resource group
When you’re provisioning resources, it’s good to think about the resource group structure that best suits your needs e.g. based on access chema

```

## Azure subscriptions

![[Pasted image 20230712232837.png]]

- Billing boundary - Determine **how an Azure account is billed** when using Azure
- Access control boundary - Create separate subscriptions to **reflect different organizational structures**
- Creating additional Azure subscriptions could be for
	- Environments
	- Organizational structures
	- Billing

## Azure Management Groups

- Facilitate the hierarchical ordering of Azure resources into collections, at a level of scope **above subscriptions**.
- Distinct governance conditions can be applied to each management group, with Azure Policy and Azure role-based access controls (RBAC), to manage Azure subscriptions effectively.
- Benefits:
	- Unified policy & access management across a hierarchy of resources
	- Efficient organization & management of multiple subscriptions
	- Ability to **define custom roles** & **assign** them to management groups
- Limitations:
	- **Only one management group can be defined** in the assignable scopes of a new role
	- Resource provider data plane actions **can't be defined** in management group custom roles (Custom roles for management groups are limited to management plane actions and cannot define data plane actions specific to resource providers.)
	- Role definitions **can't be separated from their assignments** within the hierarchy (When a custom role is assigned to a management group, the role definition and assignment are tied to that specific management group and cannot be separated within the hierarchy)
- Only 10,000 management groups can be supported in a single directory
- All subscriptions within a single management group must **trust the same Azure Active Directory (Azure AD) tenant**.
- Use case(s):
	- **Apply policies** to limit VM locations
	- Provide user access to multiple subscriptions

```ad-tip
- The resources and subscriptions assigned to a management group **automatically inherit** the conditions applied to the management group
- When using management groups, it is crucial to **make all existing subscriptions children of the root management group**

```

```ad-warning
- Management groups in Azure can have only **ONE** parent.
- To move a management group or subscription to a different parent, the user needs **management group write access** on the **existing parent** and **target parent management groups**. => **Ensure proper permission and access control** during the move operation.
```

![[Pasted image 20230712234722.png]]

```ad-note
The location you choose for the resource group **has nothing to do** with the location you choose to deploy your resources in. A resource group acts as a container for all the resources that it includes and nothing more.

```

---
# Compliance standards

- Azure infra: ISO 27001, HIPAA, FedRAMP, SOC 1, SOC 2

---
# Azure AD Tenant

- Used to store user accounts for Microsoft's cloud offerings
- Include accounts & groups for an organization

```ad-note
**Paid or trial subscriptions of Microsoft 365 or Dynamics 365 include a free Azure AD tenant.** => When organizations subscribe to Microsoft 365 or Dynamics 365 plans, they also receive a free Azure AD tenant for identity management and authentication purposes

```