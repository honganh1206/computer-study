
Azure Container Instances (ACI) offers **the fastest and simplest way to run a container in Azure**, without having to manage any virtual machines and without having to adopt a higher-level service.


## Explore Azure Container instances

- Azure Container Instances (ACI) is a great solution for any scenario that can **operate in isolated containers**, including simple applications, task automation, and build jobs.
- Benefits:
	- Fast startup
	- Direct container access
	- Hypervisor-level
	- Customer data
	- Custom sizes
	- Persistent storage
	- Linux and Windows

## Container groups

- A collection of containers that get scheduled on the same host machine
- Share a lifecycle, resources, local network, and storage volumes => Similar to pods in K8S


![[Pasted image 20240518103636.png]]


## Deployment

Use ARM when including other Azure service resources / YAML file if your deployment includes only container instances

## Resource allocation

Azure Container Instances allocates resources such as CPUs, memory, and optionally GPUs (preview) to a container group by **adding the resource requests of the instances in the group**.


## Networking

- Container groups share an IP address and a port namespace on that IP address => To enable external clients to reach a container within the group, **you must expose the port on the IP address and from the container**.
- No support for port mapping

## Storage

Supported volumes:

- Azure file share
- Secret`
- Empty directory
- Cloned git repo

## Exercise: Deploy a container


```bash
# Create resource group
az group create --name az204-aci-rg --location <myLocation>
# Unique DNS name to expose your container to the internet
DNS_NAME_LABEL=aci-example-$RANDOM
# Create a container 
az container create --resource-group az204-aci-rg \
    --name mycontainer \
    --image mcr.microsoft.com/azuredocs/aci-helloworld \
    --ports 80 \
    --dns-name-label $DNS_NAME_LABEL --location <myLocation>

# Verify the container
az container show --resource-group az204-aci-rg \
    --name mycontainer \
    --query "{FQDN:ipAddress.fqdn,ProvisioningState:provisioningState}" \
    --out table

# Clean up the resource 
az group delete --name az204-aci-rg --no-wait

# Set env vars
az container create \
    --resource-group myResourceGroup \
    --name mycontainer2 \
    --image mcr.microsoft.com/azuredocs/aci-wordcount:latest 
    --restart-policy OnFailure \
    --environment-variables 'NumWords'='5' 'MinLength'='8'\

# Set secrets with yaml file
az container create --resource-group myResourceGroup \
    --file secure-env.yaml \

# Mount volume 
az container create \
	--resource-group $ACI_PERS_RESOURCE_{GROUP}\
	--name hellofiles \ 
	--image mcr.microsoft.com/azuredocs/aci-hellofiles \
	--dns-name-label aci-demo \
	--ports 80 \
	--azure-file-volume-account-name $ACI_PERS_STORAGE_ACCOUNT_NAME \
	--azure-file-volume-account-key $STORAGE_KEY \
	--azure-file-volume-share-name $ACI_PERS_SHARE_NAME \ # Specify share and volume mount point
	--azure-file-volume-mount-path /aci/logs/
```

- Example YAML file to secure values

```yaml
apiVersion: 2018-10-01
location: eastus
name: securetest
properties:
  containers:
  - name: mycontainer
    properties:
      environmentVariables:
        - name: 'NOTSECRET'
          value: 'my-exposed-value'
        - name: 'SECRET'
          secureValue: 'my-secret-value'
      image: nginx
      ports: []
      resources:
        requests:
          cpu: 1.0
          memoryInGB: 1.5
  osType: Linux
  restartPolicy: Always
tags: null
type: Microsoft.ContainerInstance/containerGroups
```


- Deploy container and mount volumes with YAML files

```yml
apiVersion: '2019-12-01'
location: eastus
name: file-share-demo
properties:
  containers:
  - name: hellofiles
    properties:
      environmentVariables: []
      image: mcr.microsoft.com/azuredocs/aci-hellofiles
      ports:
      - port: 80
      resources:
        requests:
          cpu: 1.0
          memoryInGB: 1.5
      volumeMounts:
      - mountPath: /aci/logs/
        name: filesharevolume
  osType: Linux
  restartPolicy: Always
  ipAddress:
    type: Public
    ports:
      - port: 80
    dnsNameLabel: aci-demo
  volumes:
  - name: filesharevolume
    azureFile:
      sharename: acishare
      storageAccountName: <Storage account name>
      storageAccountKey: <Storage account key>
tags: {}
type: Microsoft.ContainerInstance/containerGroups
```


- Mount multiple volumes:

```json
// Create 2 Azure File shares in a storage account
"volumes": [{
  "name": "myvolume1",
  "azureFile": {
    "shareName": "share1",
    "storageAccountName": "myStorageAccount",
    "storageAccountKey": "<storage-account-key>"
  }
},
{
  "name": "myvolume2",
  "azureFile": {
    "shareName": "share2",
    "storageAccountName": "myStorageAccount",
    "storageAccountKey": "<storage-account-key>"
  }
}]
```