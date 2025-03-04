# Roles

![[Pasted image 20231005135509.png]]

- (By Azure Definition) A collection of **actions** that the assigned identity will be able to perform => **What** can be done?
# Security Principals

![[Pasted image 20231005140751.png]]

- An Azure object (identity) that can be assigned to a role e.g. users, groups or applications => **Who** can do it?
# Scopes

![[Pasted image 20231006160433.png]]


- One or more Azure resources that access applies to => Where it can be done?

# Role-Based Access Control (RBAC)

- **Authorization system** built on Azure Resource Manager (ARM)
- Designed for **fine-grained access management** of Azure Resources
- Role assignment is a combination of
	- **Role definition** - List of permissions
	- **Security principals** - User, groups, service principals and managed identities
	- **Scope** (Hierarchical) - Resource < resource group < subscription < management groups
- Built-in + custom roles are supported

```ad-note
title: Granting a role in Azure Portal
1. Navigate to Azure resource/resource group/subscription/management group
2. Open Access Management blade (IAM)
3. Click Add Role Assignment button
4. Select Role + Security Principal
5. Click Save button
```


```ad-info
A Website Contributor role is **much less privileged** than an Owner, as it is only **targeting Azure Websites**

```
