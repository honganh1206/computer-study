# Azure Blueprints

## Definition
- Allow you to standardize cloud subscription or environment deployments.
- Help you define repeatable settings and policies that are applied as new subscriptions are created instead of configuring features for each new subscriptions

## [Understand resource locking in Azure Blueprints](https://learn.microsoft.com/en-us/azure/governance/blueprints/concepts/resource-locking)
## Artifacts

- Each component in the blueprint definition is known as an artifact.

```ad-todo
title: Info
It is possible for artifacts to have no additional parameters (configurations). An example is the Deploy threat detection on SQL servers policy, which requires no additional configuration.

```

- Azure Blueprints deploy **a new environment based on all of the requirements, settings, and configurations** of the associated artifacts. Artifacts can include things such as:
	- Role assignments
	- Policy assignments
	- Azure Resource Manager templates
	- Resource groups

- Azure Blueprints are **version-able**, allowing you to create an initial configuration and then make updates later on and assign a new version to the update.

```ad-warning
Azure Blueprint locks **CANNOT** be overridden by the subscription owner or any other user, even if the blueprint assignment has set a locking mode.
```


---
# Azure Policy
## Definition
- Azure Policy is a service in Azure that enables you to create, assign, and manage policies that control or audit your resources.
- Usage:
	- Enables you to define both individual policies and groups of related policies
	- Evaluates your resources and highlights resources that aren't compliant with the policies you've created
	- Prevent noncompliant resources from being created

```ad-warning
Azure Policy evaluates resource state based on **defined rules and conditions**, rather than who made the change or who has permission to make a change.

```

## Features

- Can be set at each level
-  Comes with **built-in policy and initiative definitions** for Storage, Networking, Compute, Security Center, and Monitoring.
- Automatically **remediate noncompliant resources and configurations** to ensure the integrity of the state of the resources

## Azure Policy Initiatives

- A way of **grouping related policies together**
- Included policy definitions:
	- **Monitor unencrypted SQL Database**
	- **Monitor OS vulnerabilities in Security Center**
	- **Monitor missing Endpoint Protection in Security Center**

---
# Resource locks

A resource lock prevents resources from being accidentally deleted or changed.
![[Pasted image 20230809144819.png]]

```ad-important
- Only **the Owner and the User Access Administrator built-in roles** can create and delete management locks.
- If a VM has a Read-only lock applied, you **CAN** add a Delete lock as well

```

```ad-warning
Some resources, such as extensions or specific resource types, may **not** inherit locks from their parent resources.

```


---
# [Service Trust portal](https://learn.microsoft.com/en-us/purview/get-started-with-service-trust-portal)

- The Microsoft Service Trust Portal is a portal that **provides access to various content, tools, and other resources** about Microsoft security, privacy, and compliance practices.
- Types of resources
	- Existing customers with Microsoft 365/Dynamics 365/Azure subscriptions
	- New customers and customers evaluating Microsoft online services
- The **Reports, Whitepapers, and Artifacts** section in the Service Trust Portal contains a variety of information
	- Business Continuity and Disaster Recovery (BCP and DR) documents
	- Attestation reports on penetration tests and security assessments conducted by third parties
	- Privacy and data protection resources
	- Whitepapers and answers to frequently asked questions.

```ad-note
To view restricted documents in the Service Trust Portal, the user needs to have the **Tenant Admin role**.

```

---
## [My Library](https://learn.microsoft.com/en-us/purview/get-started-with-service-trust-portal#my-library)

- Can be used to perform several actions:
	- Add documents and resources to their personal library for quick access
	- Subscribe to receive email notifications for document updates
	- Export a download history of previously downloaded documents
	- Subscribe to document series for automatic updates

## Privacy statement

- Explains the personal data Microsoft processes, how Microsoft processes the data, and the purpose of processing the data.


---
# GUI of Azure Portal

The Azure portal provides a GUI to
- View all the services you are using
- Create new services
- Configure your services
- View reports.

---

# [Modern Lifecycle Policy](https://learn.microsoft.com/en-us/lifecycle/policies/modern)

- Before ending support for a service, Microsoft provides a *minimum* of **12-month notice**

