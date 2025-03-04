
> [!info] What is Azure Container Registry (ACR)?
> 
> Azure Container Registry (ACR) is a **managed, private Docker registry service** based on the open-source Docker Registry 2.0. **Create and maintain Azure container registries** to store and **manage your private Docker container images**.


| Terms              | Definition                                                               |
| ------------------ | ------------------------------------------------------------------------ |
| container registry | A place to store container images and share them out via pushing/pulling |
|                    |                                                                          |


## Discover the Azure Container Registry

### Use cases

Deployment targets:

- Scalable orchestration systems: Manage containerized applications across clusters of hosts (K8S, DC/OS, Docker Swarm)
- Azure services: Support + build applications at scale (AKS, App Service, Batch, etc.)

> [!tip]
> - Developers can also push to a container registry as part of a container development workflow.
> - You can **configure ACR Tasks** to automatically rebuild application images when their base images are updated.


### Service tiers

Basic/Standard/Premium

### Supported images and artifacts

- Azure container registries can **include both Windows and Linux images**.



## Explore Storage capabilities

- Encryption-at-rest
- Regional storage
- Zone redundancy
- Scalable storage

## Build & Manage container with tasks

## Explore elements of a Dockerfile


```dockerfile
# Use the .NET 6 runtime as a base image
FROM mcr.microsoft.com/dotnet/runtime:6.0

# Set the working directory to /app
WORKDIR /app

# Copy the contents of the published app to the container's /app directory
COPY bin/Release/net6.0/publish/ .

# Expose port 80 to the outside world
EXPOSE 80

# Set the command to run when the container starts
CMD ["dotnet", "MyApp.dll"]
```
