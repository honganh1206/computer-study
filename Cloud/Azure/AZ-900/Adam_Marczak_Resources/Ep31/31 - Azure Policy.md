
![[Pasted image 20231006222824.png]]

- Help with governance, security, compliance, cost management, etc.
- Policies focus on **resource properties**, while RBAC focuses on **user actions**
- Policy definition
	- Define what should happen with **condition** (if/else) and the **effect** (deny, audit, append, modify, etc.)
	- Examples include:
		- _Allowed resource types_
		- _Allowed locations_
		- _Allowed Stock Keeping Units (SKUs) _
		- _Inherit resource tags_
	- Support **built-in** and **custom** policies
- **Policy initiative** - A _group of policy definition_
- **Policy assignment** - Assigning a policy definition/initiative to a scope (**Inheritable**)

```ad-info
Policies allow **exclusion of scopes**

```
