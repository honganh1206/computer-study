
# Factors that can affect costs in Azure

Azure shifts development costs from the capital expense (**CapEx**) of building out and maintaining infrastructure and facilities to an operational expense (**OpEx**) of renting infrastructure as you need it

1. Resource types

2.  Consumption
	- Azure also offers the ability to **commit to using a set amount of cloud resources** in advance and **receiving discounts on those “reserved” resources**
3.  Maintenance
4. Geography
5. Network Traffic
6. Subscription type
7. Azure Marketplace
	- When you purchase products through Azure Marketplace, you may pay for not only the Azure services that you’re using, but also the services or expertise of the third-party vendor. Billing structures are set by the vendor.
	- Used by IT professionals to **provision their Azure solutions**

---
# Compare the Pricing and Total Cost of Ownership calculators

## Pricing calculator

- The pricing calculator is designed to give you **an estimated cost** for **provisioning resources in Azure**

```ad-info
title: Note
The Pricing calculator is for **information purposes** only. The prices are only an **estimate**. Nothing is provisioned when you add resources to the pricing calculator, and you won't be charged for any services you select

```

## Total Cost of Ownership (TCO) Calculator
- The TCO calculator is designed to help you **compare the costs for running an on-premises infrastructure compared to an Azure Cloud infrastructure.


---
# Azure Cost Management tool

Cost Management provides the ability to 
- Quickly check Azure resource costs
- Create alerts based on resource spend
- Create budgets that can be used to automate management of resources.

---
# Tags

 Tags provide extra information, or metadata, about your resources. This metadata is useful for:
 - Resource management
 - Cost management + optimization
 - Security
 - Governance and regulatory compliance
 - Workload optimization and automation

## Manage resource tags
-  Add, modify, or delete resource tags through Windows PowerShell, the Azure CLI, Azure Resource Manager templates, the REST API, or the Azure portal.
- Use **Azure Policy** to enforce tagging rules and conventions

```ad-note
**Resources don't inherit tags from subscriptions and resource groups**, meaning that you can apply tags at one level and not have those tags automatically show up at a different level

```

---
# Azure Reservations

- Offers discounted prices on certain Azure services => Save you up to **72 percent** compared to pay-as-you-go prices
- How to:  Reserve services and resources by paying **in advance** => Spending limits can suspend a subscription when the spend limit is reached.

---
# Azure Support Plan

- Allow these support requests:
	- Developer
	- Basic
	- Standard
	- Professional direct

---
## [Microsoft Cost Management and Billing](https://learn.microsoft.com/en-us/azure/cost-management-billing/cost-management-billing-overview)

-  **A suite of tools** that help organizations monitor, allocate, and optimize the cost of their Microsoft Cloud workloads