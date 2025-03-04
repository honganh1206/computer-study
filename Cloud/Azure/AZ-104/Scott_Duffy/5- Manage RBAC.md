# RBAC

## Problems with granting access in the old way

- Principle of Least Privilege - Users should have the least amount of administration
- Some users have too many permissions/Some have little or not enough
- More effort + cost to maintain
- Slow down everybody => Lower productivity
- Higher chance of malicious user gaining access to the system

## Three types of permission

- Owner
- Contributor
- Reader

## How RBAC works

- Assign role(s) to an user
- Assign permissions to the role(s) (not the user)

## Benefits of RBAC

- Abstraction => Simplify management => Fewer errors
- Only need to **confirm users are in the right role**
- All users in one role are treated the same => No extra secret permissions
- Easier to add new users and assign the correct permissions

## Switch storage account from access key to RBAC

- Go to your resource group > Your storage account > Configuration
- Disable "Allow storage account key access" + Enable "Default to Microsoft Entra authorization in the Azure portal"