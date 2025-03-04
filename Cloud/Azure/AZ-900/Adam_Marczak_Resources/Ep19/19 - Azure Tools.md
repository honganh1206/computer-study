# Azure Portal

- Web-based interface for Azure platform management
- Designed for **self-service**
- High availability
- Continuous updates with no downtime
- Customizable
- Simple tasks

```ad-warning
Azure Portal is not fit for big deployment/automation tasks

```

# Azure PowerShell

- PowerShell module for common Azure Administrative tasks
- Designed for **automation**
- **Multi-platform** with **PowerShell Core**
- Sample commands:
	- `Connect-AzAccount` - Log into Azure
	- `Get-AzResourceGroup` - List resource groups
	- `New-AzResourceGroup` - Create new resource group
	- `New-AzVm` - Create VM

# Azure CLI
- Multi-platform
- Sample commands:
	- `az login`
	- `az group list`
	- `az group create`
	- `az vm create`

# [Azure Cloud Shell](https://learn.microsoft.com/en-us/azure/cloud-shell/features)

![[Pasted image 20230929151729.png]]

- **Cloud-based**
- Free
- Support both PowerShell and CLI
- Features:
	- Secure automatic authentication
	- $HOME persistence across sessions
	- Integration with open-source tooling
	- Can be used to manage Exchange Online
- Additional tools
- Multiple client interfaces
	- Portal integration (portal.azure.com)
	- Shell portal (shell.azure.com)
	- VS Code extension
	- Windows terminal
	- Azure Mobile App
	- Microsoft Docs integration
- 5 GB of storage capacity 
- Permission: Regular Linux user

```ad-warning
Since Cloud Shell is built for interactive sessions, shells automatically terminate after 20 minutes of shell inactivity.

```
