
# Resource Locks

## Specific locks

![[Pasted image 20231006164456.png]]

## Resource group-level locks

![[Pasted image 20231006164600.png]]

- Prevent accidental deletion and/or modification
- Used **in conjunction with RBAC**
- Two types of locks
	- Read-only
	- Delete
- Locks are **hierarchical** + **inheritable** as scopes
- Only **Owner** and **User Access Administrator** roles can manage locks (built-in roles)

```ad-warning
The highest level level of resource locks is **Subscription**
![[Pasted image 20231006164626.png]]
```

