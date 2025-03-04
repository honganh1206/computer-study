
# [Course materials](https://on24static.akamaized.net/event/42/31/63/0/rt/1/documents/resourceList1684303839062/original.pdf)

# Storage account name
- Must have unique names + all lowercase

## Azure storage services
- Container storage / blob
	- Used for unstructured data (text, binary data, images etc.)
	- Other data types
		- Semi-structured (JSON)
		- Structured (Table)
- Disk storage
	- Provide disks for VMs, apps and other services
- Azure files
	- Set up highly available network file shares

## Azure storage access tiers
- Hot - Data accessed frequently
- Cool - Data accessed infrequently and stored for at least 30 days
- Archive - Data accessed rarely and stored for at least 180 days

# Azure migrate
- Unified migration platform
- Include integrated + standalone tools
- Assessment and migration

# Azure Data Box
- Store up to **80 petabytes** of data
- Can move disaster recovery backups to Azure
- Protect data during transit
- Migrate data out of Azure for compliance/needs
- Migrate data to Azure from **remote locations with limited/no connectivity**

## File management options
![[Pasted image 20230706145812.png]]

--- 
# Identity & Access 
## Azure Active Directory
This offers:
- Authentication
- Single sign-on (SSO)
- App management
- Business to business (B2B)
	- External identities
- Business to Customer (B2C)
- Device management

### Authentication vs. Authorization
![[Pasted image 20230706151601.png]]

## Azure Multi-Factor Authentication (MFA)

Provides additional security by requiring **two or more elements** for authentication
=> Something you know (Username + Password) <> Something you possess (PC/Phones) <> Something you are (Biosecurity data)

## External Identities B2B
![[Pasted image 20230706152256.png]]

## External Identities B2C
```ad-todo

Used for customer-facing app
```

![[Pasted image 20230706152547.png]]

## Conditional access

## Azure role-based access control
- **Segregate duties within the team** => Grant only the right amount of access to users for their work
- Enable access to Azure portal and control access to resources
- Users can only access our application **via approved/managed devices**

## Defense in depth
- Provide multiple levels of protection with one layer isolated from subsequent layers

## Zero trust
Protect assets anywhere with central policy => No room for confusion or doubt

## Total cost of Ownership (TCO)

## Azure Cost Management

## Tags
Provide metadata for Azure resources for logical organization

# Azure Marketplace
- Find, try, purchase, and provision applications and services certified by Azure

---
# Governance and Compliance
## Azure Blueprints - Governance

## Azure Policy - Compliance
- Enforce organizational standards to assess compliance at-scale
- Inherited: Policies can be inherited to underlying groups

## Resource locks
Protect Azure resources from accidental deletion or modification (Delete/ReadOnly)

## Service Trust Portal

---
# Azure Resource Management

