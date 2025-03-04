
## Introduction

## Examine Azure App Service

- CI/CD support: Out-of-the-box continuous integration and deployment with Azure DevOps Services, GitHub, Bitbucket, FTP, or a local Git repository on your development machine *=> No Gitlab support*

- Deployment slots
	- Deployment slots are **live apps with their own host names**.
	- App content and configurations elements can be **swapped** between two deployment slots, including the production slot

- App Service on Linux
	- Host web apps natively on Linux for supported application stacks
	- Retrieve supported languages with this command

```bash
az webapp list-runtimes --os-type linux
```

## Examine Azure App Service plans

- Each App Service plan defines:
	- OS
	- Region
	- Number of VM instances
	- Size of VM instances
	- Pricing tier

- Categories in pricing tiers
	- Shared compute: Run apps on the same VM as other App Service apps, including apps of other customers
	- Dedicated compute: Run apps on **dedicated VMs** => Apps in the same App Service plan share the same compute resources only
	- Isolated: Run dedicated Azure VMs on dedicated Azure Virtual Networks

- How does my app run and scale? => App Service plan is the **scale unit** of the App Service apps
	- Free/Shared tier: App receives CPU minutes + Cannot scale out
	- Other tiers
		- Multiple apps in the same App Service plan => Share the same VM instances
		- Multiple deployment slots => Run on the same VM instances


## Deploy to App Service

- Automated deployment: Azure Devops/GitHub/Bitbucket
- Manual deployment: Git/CLI (`webapp up`)/Zip deploy/FTP/S

## Examine Authentication & Authorization in App Service

> [!note]
> 
> You are **NOT** required to use App Service for authentication/authorization, as many web frameworks are bundled with security features


### How it works

- The authentication and authorization module **runs in the same sandbox** as your application code.
- This module runs **separately** from your application code + Can be configured with ARM settings/config files => No SDKs, specific programming languages, or changes to your application code are required.

## Discover App Service networking feature

- Two main deployment types
	- Multitenant public services => All pricing tiers from Free to Premium V3
	- Single-tenant App Service Environment => Host isolated SKU

### Multi-tenant App Service

- Because there are many different customers in the same App Service scale unit, **you can't connect the App Service network directly to your network**

### Default networking behavior

#### Outbound addresses

- The outbound addresses used by your app for making outbound calls are listed in the **properties** for your app.
- These addresses are **shared by all the apps running on the same worker VM family** in the App Service deployment
- Can be controlled by **Hybrid Connections** feature
- Command to list all outbound IP addresses

```bash
az webapp show \
    --resource-group <group_name> \
    --name <app_name> \ 
    --query outboundIpAddresses \
    --output tsv
```

### Exercises

#### Create a static HTML web app by using Azure Cloud Shell

- Create a folder + cd to the folder
- Clone the app
- Set variables

```bash
resourceGroup=$(az group list --query "[].{id:name}" -o tsv)
appName=az204app$RANDOM
```

- Run the app

```bash
az webapp up -g $resourceGroup -n $appName --html
```

- Update the app with the same `up` command after making some changes