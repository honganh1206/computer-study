# Directory services in Azure

## Azure Active Directory / Microsoft Entra ID

- Enable us to sign in and access **both Microsoft cloud applications and cloud applications that we develop**
- Allow us to control the identity accounts similar to Active Directory of on-premises environments instead **available globally**
- Monitor sign-in attempts and detect the suspicious ones

```ad-warning
- AAD is on applicable on Windows 10 devices
- Require **NO** selection of a particular region to work

```


```ad-info
- An Azure subscription has a **trust relationship** with Azure AD. A subscription trusts Azure AD to authenticate users, services, and devices.
- Azure subscription is a **logical unit** of Azure services that *links Azure services* to an Azure account
```


- Who this is for:
	- IT admins
	- App developers
	- Users
	- Online service subscribers e.g. Microsoft 365 subscribers

- What does Azure AD do?
	- Authentication
	- SSO
	- Application management
	- Device management

- Connect on-premises Active Directory with Azure AD
	- Connect via **Azure AD Connect**
		- Sync user identities between on-premises AD and Azure AD
		- Sync changes between both systems => We can use features like SSO, multifactor authentication, and self-service password under **both systems**

- License options:
	- Azure AD Free
	- Azure AD Premium P1 + P2
	- Azure AD Business to Customer (B2C)

```ad-tip
Azure Active Directory for developers allows you to **build apps that sign in all Microsoft identities**.

```


### License options

- P2:
	- Risk-based Conditional Access => Allowing administrators to **define access policies based on risk factors** and provide **real-time threat detection capabilities**.
	- Privileged Identity Management => **Advanced administrative capabilities** for managing privileged accounts

### Password hash synchronization

- DOES NOT require additional infrastructure deployment
- Allows **password synchronization hashes** from an on-premises Active Directory environment to Azure AD

```ad-warning
- External users in B2B collaboration **DO NOT** authenticate with their credentials stored in your Azure AD organization.
- Azure AD password hash synchronization has a **delayed** enforcement of changes in on-premises account states.

```


## Azure AD Domain Service

- **Provide managed domain services** such as domain join, group policy, LDAP, etc.
- Allow us to take advantages of domain services **without the need to deploy, manage, and patch the domain controllers (DCs) in the cloud**
- Allow us to **run legacy applications**
- Integrate with existing Azure AD tenant => Allow users to sign into services and applications connected to the managed domain using existing credentials

### How it works

1. Create an Azure AD DS domain => Define a unique namespace/domain name
2. Two Windows Server domain controllers are then deployed into your selected Azure region => Replica set
3. No need to manage, configure, or update the two Window Server DCs

```ad-info
title: Synchronizing information
A managed domain is configured to perform **a one-way synchronization** from Azure AD to Azure AD DS.

![[Pasted image 20230802233107.png]]

```


---
# Authentication methods in Azure

![[Pasted image 20230802233730.png]]

## SSO
### Definition
- Allow user to **sign in one time and use that credential to access multiple resources and applications from different providers**
- Different apps and providers **must trust the initial authenticator**
- With SSO, **access is tied to a single identity**

```ad-info
Single sign-on is only as secure as the initial authenticator because the subsequent connections are all based on the security of the initial authenticator.

```

## Multifactor Authentication (MFA)
- Provide additional security by **requiring two or more elements for authentication**
- Elements:
	- Something the user knows - A challenge question
	- Something the user has - The code sent to the user's phone
	- Something the user is - Biometric property

![[Pasted image 20230805181104.png]]


## Passwordless authentication
- The password is removed and replaced with **something you have + something you are/know**
- Passwordless authentication needs to be setup on a device to work (Device association)

---
# External identities and guest access
- Azure AD External Identities refers to all the ways you can securely interact with **users outside of your organization**.

![[Pasted image 20230805203418.png]]


### Business to business (B2B) collaboration

- Collaborate with external users by **letting them use their preferred identity to sign-in to your Microsoft applications** or other enterprise applications
-  B2B collaboration users are represented in your directory, typically as **guest users**.

### B2B direct connect

-  Establish **a mutual, two-way trust with another Azure AD organization** for seamless collaboration.

### [Azure AD business to customer (B2C)](https://learn.microsoft.com/en-us/azure/active-directory-b2c/overview)

- Separate service from Microsoft Entra ID + Azure AD
- Publish modern SaaS apps or custom-developed apps (excluding Microsoft apps) to consumers and customers, while using Azure AD B2C for identity and access management.
---
# Azure AD Conditional Access (CA)

- Conditional Access is a tool that Azure Active Directory uses to **allow (or deny) access to resources based on identity signals**.
- Conditional Access also provides a more granular multifactor authentication experience for users.
	- E.g. An user might not be challenged for a second authentication if they are at a known location, but they will be if their sign-in signals are unusual/they are at an unknown location

## How things work

1. Collects signals from the user
2. Makes decisions based on those signals
3. Enforces that decision by allowing or denying the access request/challenge a MFA

![[Pasted image 20230805205512.png]]

### When to use CA
- MFA
- Require access to services only through approved client applications.
- Require users to access your application only from managed devices.
- Block access from untrusted sources

---
# [Azure Role Based Access Control (RBAC)](https://learn.microsoft.com/en-us/azure/role-based-access-control/overview)

- Role-based access control is **applied to a scope**, which is a resource or set of resources that this access applies to.

![[Pasted image 20230805210421.png]]

- Scopes include:
	- A management group (a collection of multiple subscriptions).
	- A single subscription.
	- A resource group.
	- A single resource.

- Azure RBAC is **hierarchical**, in that when you grant access at a parent scope, those permissions are inherited by all child scopes.

```ad-info
Role assignments are **transitive** for groups which means that *if a user is a member of a group and that group is a member of another group that has a role assignment, the user will have the permissions in the role assignment.

```

## Enforcing Azure RBAC

- Azure RBAC doesn't enforce access permissions at the application or data level. **Application security must be handled by your application**.
- Allow model: When you're assigned a role, Azure RBAC allows you to **perform actions within the scope of that role**.
	-  If one role assignment grants you read permissions to a resource group and a different role assignment grants you write permissions to the same resource group, you have both read and write permissions on that resource group

---
# Zero Trust

Zero Trust is a security model that **assumes the worst case scenario** and **protects resources with that expectation**.

```ad-warning
Zero Trust is **NOT** a specific product or service offered by Microsoft or any other company. It is **a security framework or approach to cybersecurity** that **emphasizes the need to verify and authenticate every request for access**, regardless of the location or context of the request.

```


### Guiding principles
- **Verify explicitly**: Always authenticate and authorize
- **Use least privilege access**: Limit user access with Just-In-Time and Just-Enough-Access (JIT/JEA)
- **Assume breach** 
	- Minimize blast radius and segment access. 
	- Verify end-to-end encryption. 
	- Use analytics to get visibility, drive threat detection, and improve defenses.

![[Pasted image 20230805211627.png]]

---
# Defense in depth (DID) model

## Objective:
Protect information and prevent it from being stolen by those who aren't authorized to access it. => Slow the advancement of an attack that aims to gain unauthorized access to data

## Layers of DID

![[Pasted image 20230805211743.png]]

- The physical security layer is the first line of defense to **protect computing hardware in the datacenter**.
- The identity and access layer **controls access to infrastructure and change control.**
- The perimeter layer **uses distributed denial of service (DDoS) protection to filter large-scale attacks** before they can cause a denial of service for users.
- The network layer **limits communication between resources** through segmentation and access controls.
- The compute layer **secures access to virtual machines**.
- The application layer helps **ensure that applications are secure and free of security vulnerabilities**.
- The data layer **controls access to business and customer data** that you need to protect.

---
# Microsoft Defender for Cloud

Defender for Cloud is **a monitoring tool for security posture management and threat protection**. 

## Everywhere protection

When necessary, Defender for Cloud can automatically deploy a Log Analytics agent to gather security-related data.
- For Azure machines, deployment is handled **directly**. 
- For hybrid and multi-cloud environments, Microsoft Defender plans are **extended to non Azure machines** with the help of **Azure Arc**.

## Azure-native protections

Defender for Cloud are provided across
- Azure PaaS services
- Azure data services
- Networks

## Defend hybrid resources

To extend protection to on-premises machines, deploy **Azure Arc** and enable Defender for Cloud's enhanced security features.

## Defend resources running on other clouds

If you connect an AWS account to an Azure subscription, you can enable any of these protections:
- Defender for Cloud's CSPM features extend to your AWS resources
- Microsoft Defender for Containers
- Microsoft Defender for Servers

## Assess, Secure and Defend

![[Pasted image 20230805212846.png]]

---
