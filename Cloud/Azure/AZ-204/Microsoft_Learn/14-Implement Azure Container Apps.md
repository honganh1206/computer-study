
## Azure Container Apps

- Run microservices/containerized apps on a **serverless platform** that runs on top of AKS

### Environments

- Individual container apps are deployed in a single Container Apps environment (which acts as a secure boundary between groups of container apps)

## Deploy a container app

```bash
az extension add --name containerapp --upgrade # Install Azure Container Apps extension
az provider register --namespace Microsoft.App # register namespace
az provider register --namespace Microsoft.OperationalInsights # register for Azure Azure Monitor Log Analytics workspace

# Set env vars
myRG=az204-appcont-rg
myLocation=<location>
myAppContEnv=az204-env-$RANDOM

az group create \
    --name $myRG \
    --location $myLocation
# Create an environment

az containerapp env create \
    --name $myAppContEnv \
    --resource-group $myRG \
    --location $myLocation

# Create a container app
az containerapp create \
    --name my-container-app \
    --resource-group $myRG \
    --environment $myAppContEnv \
    --image mcr.microsoft.com/azuredocs/containerapps-helloworld:latest \
    --target-port 80 \
    --ingress 'external' \
    --query properties.configuration.ingress.fqdn

# Cleanup
```

## Explore containers in Azure Container Apps

> [!tldr]
> 
> - ACA can be used to manage containers of different platforms or languages via ARM template. 
> - Multiple containers can be used to implement the sidecar pattern. 
> - You can use ACA with private registries using credentials.

ACA can:
- Manage details of K8S and container orchestration for you
- Use ant runtime, programming language, or development stack of choice
- Support Linux-based x86-64 container image


![[Pasted image 20240608221423.png]]

- Containers can be set up using ARM templates

### Multiple containers

- You can define multiple containers in a single container app to implement the sidecar pattern (deploy components of an application into a separate process/container - a sidecar attached to a motorcycle)
- Sidecar containers might contain:
	- An agent that read logs from the primary app container
	- A background process that refreshes a cache

### Container registries

You can deploy images hosted on private registries by **providing credentials** in the Container Apps configuration.


```json
{
  ...
  "registries": [{
    "server": "docker.io",
    "username": "my-registry-user-name",
    "passwordSecretRef": "my-password-secret-name"
  }]
}
```


## Implement authentication and authorization in Azure Container Apps


> [!tldr]
> - ACA provides authentication and authorization from different providers. 
> - ACA uses a middleware component running as a sidecar to handle tasks.
> - The authentication flow differs whether it is with server-flow (delegate sign-in to Container Apps) or client-flow (use Container Apps for token validation)


- ACA provides built-in authentication + authorization with minimal/no code
	- Various built-in authentication providers (Google/Facebook/Github/OpenID/etc.) without requiring specific language/SDK/security expertise
	- Used with HTTPS => Disable `allowInsecure` on your container app’s ingress configuration

### Feature architecture

- Authentication and authorization middleware component runs as a sidecar container on each replica of your application

![[Pasted image 20240608225122.png]]

- Middleware’s tasks:
	- Authenticate users and clients
	- Manage the authenticated session
	- Inject identity information into HTTP request headers

### Authentication flow

The authentication flow differs depending on whether you want to sign in with the provider’s SDK or not
- Without SDK (server flow): Delegate federated sign-in to Container Apps (browser-based apps)
- With SDK (client flow): The app signs users to the provider manually and submits the authentication token to Container Apps for validation (browser-less apps)


## Manage revisions and secrets in ACA

> [!tldr] 3-sentence summary
> - ACA use revisions to manage app versioning and external traffic. 
> - We can use CLI to manage details of the container app such as secrets, env vars, etc.


- ACA manages versioning by **creating revisions** (snapshots of the container app version)
- You can control which revisions are active, and the external traffic that is routed to each active revision

### Update your container app

```bash
# Modify env vars, compute resources, etc.
az containerapp update \
  --name <APPLICATION_NAME> \
  --resource-group <RESOURCE_GROUP_NAME> \
  --image <IMAGE_NAME>

# List revisions
az containerapp revision list \
  --name <APPLICATION_NAME> \
  --resource-group <RESOURCE_GROUP_NAME> \
  -o table
```

### Manage secrets

- ACA allows you to store sensitive config values at the application level
- When a secret is updated/deleted, we can deploy a new revision or restart an existing revision

> [!warning]
> 
> ACA does not support Azure Key Vault integration. We can enable managed identity in the container app + use Key Vault SDK

- Define secrets using the `--secrets` parameter

```bash
az containerapp create \
  --resource-group "my-resource-group" \
  --name queuereader \
  --environment "my-environment-name" \
  --image demos/queuereader:v1 \
  --secrets "queue-connection-string=$CONNECTION_STRING"
```

## Distributed Application Runtime (Dapr) integration with ACA

> [!tldr] 3-sentence summary
> 
> - Dapr is a set of features to manage microservice-based container apps via a set of APIs
> - Dapr works as a sidecar to share data/configuration values across container apps

### Dapr

- A set of feature to simplify the authoring of distributed, microservice-based applications
- APIs
	- Service-to-service invocation
	- State management
	- Publish and subscribe
	- Bindings I/O
	- Actors (Encapsulate code and data in reusable actor objs)
	- Observability
	- Secrets
- Enable Dapr via arguments and annotations (runtime context) and ACA provides three channels to configura Dapr:
	- ACA CLI
	- IaC templates
	- Azure Portal
- Scopes:
	- Provide a pluggable abstraction model
	- Can be shared across container apps
	- Dapr secrets can be used to retrieve config metadata

### Dapr core concepts

![[Pasted image 20240609110314.png]]


1. Enable Dapr at the container app with cofigurations
2. Dapr APIs are exposed following the sidecar pattern
3. Dapr component is shared across multiple container app