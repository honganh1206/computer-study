# Azure Portal

![[Pasted image 20230809153402.png]]

---
# [Azure Arc](https://learn.microsoft.com/en-us/azure/azure-arc/overview)
## Definition

-  Arc lets you extend your Azure compliance and monitoring to your hybrid/multi-cloud/edge environment configurations.**from a single control plane**
- Arc simplifies governance and management by delivering a consistent multi-cloud and on-premises management platform.
- Can manage these resource types:
	- VMs running on VMware vSphere or Azure Stack HCI
	- Windows and Linux physical servers
	- Azure SQL Managed Instance and PostgreSQL services
- Pricing model: No additional cost for Azure Arc control plane functionality
## Features

- AA-enabled servers
- AA-enabled Kubernetes => Zero-touch compliance and configuration using Azure Policy
- AA-enabled data services

---
# [Azure Resource Manager and ARM templates](https://learn.microsoft.com/en-us/azure/azure-resource-manager/templates/overview)

## [ARM](https://learn.microsoft.com/en-us/azure/azure-resource-manager/templates/overview)

### Definition

- Provides a management layer that enables you to create, update, and delete resources in your Azure account

### Benefits

- Manage infrastructure through declarative templates/code
- Deploy, manage, and monitor resources as a group
- Apply access control through Azure RBAC
- Clarify billing by viewing costs for tagged resources (By tagging resources in ARM, you can have better visibility into resource usage and costs)


```ad-warning
Compliance Manager will soon be removed from the Service Trust Portal => Use Regulatory Compliance included in Azure Security Center.

```

 - Use [Template specs](https://learn.microsoft.com/en-us/azure/azure-resource-manager/templates/overview#share-templates) to share ARM templates

---
# Area of management
### Configure
- Azure Automation => Automate configuration tasks
- Azure Backup => Backup and recovery of data in **both the cloud and on-premises**
### Secure
- Microsoft Defender for Cloud
### Protect
- Keep applications and data available during outages
### Migrate
- Azure Migrate
- Azure Site Recovery