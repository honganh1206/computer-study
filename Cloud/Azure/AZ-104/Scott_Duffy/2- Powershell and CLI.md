
> [!info]
> 
> No programming on AZ104, but there is some scripting with Powershell/Bash/CLI


# How Microsoft tests

## Method 1: Performance-based Labs

- Given an instance of Azure => Asked to perform a set of tasks any way you know how

## Method 2: Code in question

- Select the right answer e.g., Choose the line that completes the script, drag components to the right boxes

> [!tip]
> 
> - Get **lots of hands-on practice while studying** - Portal/PS/CLI
> - Leave **lots of time** for the labs

---

# Memorizing PS and CLI commands

- There is a **predictable naming system** for commands
	- [CLI Reference](https://learn.microsoft.com/en-us/cli/azure/reference-index?view=azure-cli-latest)
	- [PS Reference](https://learn.microsoft.com/en-us/powershell/module/?view=azps-11.1.0)

> [!example] CLI command examples
> 
> ```bash
> az vm list
> az network vnet create
> az network vnet subnet delete
> ```


> [!example] Powershell commands
> ```powershell
> Get-AzVM
> New-AzVM
> Remove-AzVM
>```


# Details about Powershell/CLI for managing Azure

## Install/Update AZ module

```powershell
Install-Module -Name Az -AllowClobber -Repository PSGallery -Force
Update-Module -Name Az -AllowClobber -Repository PSGallery
```

## Set subscription context to work mainly with (for multiple subscriptions)

```powershell
$context = Get-AzSubscription -SubscriptionId <Subscription ID>
Set-AzContext $context
```

