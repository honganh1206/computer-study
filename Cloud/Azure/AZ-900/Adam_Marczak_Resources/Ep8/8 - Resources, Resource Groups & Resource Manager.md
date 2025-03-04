
# Resource

![[Pasted image 20230910104621.png]]

- Objects to **manage services** in Azure
- Represent **service lifecycle**
- Saved in JSON format

# Resource Groups (RGs)

![[Pasted image 20230910104957.png]]

Organize by
- Type
- Lifecycle (app, environment)
- Department
- Billing/Location or combination of those

```ad-info
title: Resource and Resource Group
- Each resource **MUST** be in **one and only one resource group**
- Resource groups have their **own location assigned**
- Resource groups can contain resources with **different lifecycles**
- Resource and Resource Group CAN **reside in different locations**
- Resources CAN be **moved between RGs**
- RGs **CANNOT be nested**
- Consider these before organizing resources into RGs
	- Billing
	- Security and Access management
	- App Lifecycle

```

# Resource Manager (RM)

- **Management layer** for all resources + RGs
- Unified language
- Control **access** and **resources**