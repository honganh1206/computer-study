
```ad-abstract
title: Identity
The fact of being **something** or someone, typically defined with a username and password

```

```ad-abstract
title: Authentication
The process of **verification/assertion of identity**

![[Pasted image 20231001115631.png]]

```


```ad-abstract
title: Authorization
Ensure only **authenticated identities get access to the resources** for which **they have bene granted access to**

![[Pasted image 20231001115746.png]]
```

# Access Management
The process of **controlling, verifying, tracking** and **managing access** to authorized users and applications

# Azure Active Directory / Microsoft Entra ID

![[Pasted image 20231001120206.png]]


- **Identity** and **Access Management** service in Azure
	- Identity management - Users, groups, applications
	- Access management - Subscriptions, resource groups, roles, role assignments, authentication & authorization settings, etc.
- Used by multiple Microsoft platforms
	- Azure
	- Microsoft 265
	- Office 365
	- Live.com services (Skype, OneDrive, etc.)
- **Sync with on-premises** AD via **sync services**

# Multi-factor Authentication (MFA)

![[Pasted image 20231001151322.png]]

- Presenting **two or more pieces of evidence to prove one's identity**
- Factor types
	- Knowledge factor e.g. password, pin
	- Possession factor e.g. phone, token, card, key
	- Physical Characteristic factor e.g. fingerprints, voice, face, etc.
	- Location factor e.g. GPS location
- Supported by Azure AD by default (simple on-off switch)