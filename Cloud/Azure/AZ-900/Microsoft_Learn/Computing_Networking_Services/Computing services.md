# Azure Virtual Machines (VMs)

- A VM image is a template used to create a VM and **may** include an OS and other software
- IaaS offering

```ad-note
Azure VMs provide **only hardware virtualization**, not operating system virtualization.

```

## Scale VMs in Azure
### Scale sets

- Azure can create a group of identical, load-balanced VMs automatically
- VM scale sets can automatically deploy a load balancer to ensure resources being run efficiently
### Availability sets

- Ensure that VMs stagger updates and have varied power + network connectivity => **Prevent losing all VMs in emergency**
#### Update domain

- Group of domains that can be rebooted at the same time
- All of the machines in one update domain will be updated
#### Fault domain

- VMs  grouped by common power source and network switch
- An availability set will split your VMs across **up to 3 fault domains** => Protect against power/networking failure

![[Pasted image 20230714214957.png]]

## When to use VMs

- During testing and development
- Running an application in the cloud
- Extending your datacenter to the cloud
- During disaster recovery

```ad-important
title: Deploying VMs in case of emergency
If a single Azure data center fails, it is best to deploy VMs into **two or more Azure regions and Availability Zones**

```

## VM resources

Factors to consider: 
- Size (RAM, num of cores, purpose)
- Storage disks
- Networking

## Commands to run VMs

- Create a Linux VM
```bash
az vm create \
  --resource-group learn-bcd273d6-0fa6-4adf-881a-9670c04199ef \
  --name my-vm \
  --image UbuntuLTS \
  --admin-username azureuser \
  --generate-ssh-keys
```

- Configure Nginx on Linux VM
```bash
az vm extension set \
  --resource-group learn-bcd273d6-0fa6-4adf-881a-9670c04199ef \
  --vm-name my-vm \
  --name customScript \
  --publisher Microsoft.Azure.Extensions \
  --version 2.1 \
  --settings '{"fileUris":["https://raw.githubusercontent.com/MicrosoftDocs/mslearn-welcome-to-azure/master/configure-nginx.sh"]}' \
  --protected-settings '{"commandToExecute": "./configure-nginx.sh"}'
```

### [cloud-init support for virtual machines in Azure](https://learn.microsoft.com/en-us/azure/virtual-machines/linux/using-cloud-init)

---
# Azure Virtual Desktop

- A desktop and virtualization service that runs on the cloud
- Can be used to help you use a cloud-hosted version of Windows from any location
- Works across devices and operating systems
- Supported identity scenarios:
	- Azure AD with AD DS
	- Azure AD with Azure AD DS
	- Azure AD with AD FS
- To deploy Azure Virtual Desktop, **the Contributor role** is required for the Azure account.
## Enhance security

- Provide **centralized** security management for users' desktop
- Separate data and apps from the local hardware

---
# Azure Containers
## Containers - A virtualization environment

- Lightweight and designed to be created, scaled out, and stopped dynamically => Respond to changes on demand
## Azure container instances

- PaaS offering
- Allow you to upload your containers and then the service will run the containers for you
### Use containers in your solutions

- Containers are often used in microservice architecture - **Break the solutions into smaller, independent pieces**

---
# Azure Functions

- An event-driven, serverless compute option that **does not require maintaining VMs or containers**
## Serverless computing

- No infra management
- Scalability
- Pay for what you use only

## Benefits of using Azure functions - Recheck this

- Use to perform work in response to an event
- Focus on the code running your service and not the underlying platform/infra
- Either stateless - default/stateful 
- Ideal for hosting applications **with an unpredictable workload demand**

## Azure Function Proxies

- Azure Functions Proxies allow developers to **build serverless APIs and backend services with additional features**, such as request/response transformations and URL rewriting. 
- They provide a way to manage and expose APIs built using Azure Functions.

--- 
# [Azure App Service](https://learn.microsoft.com/en-us/azure/app-service/overview)

- A HTTP-based service for hosting web applications
- Used to build and host web apps, background jobs, mobile back-ends and RESTful APIs in the **programming language of your choice** without managing infra
- Offer automatic scaling and high availability
- Support **hosting web applications on both Windows and Linux** and **enables automated deployments**
- Can be used to host a **containerized** web application

## Types of app services

- Web apps
- API apps
- WebJobs
- Mobile apps

---
# [Azure Data Factory]([Introduction to Azure Data Factory - Azure Data Factory | Microsoft Learn](https://learn.microsoft.com/en-us/azure/data-factory/introduction))

- Azure Data Factory is the Azure service used for **data integration and orchestration**. 
- It provides a platform for building data pipelines that **extract, transform, and load** (ETL) data from various sources to different destinations.
- DOES NOT support the **migration of file metadata**

---

# [Azure Event Grid](https://learn.microsoft.com/en-us/azure/event-grid/overview)

- Azure Event Grid is used for **real-time event processing and routing** in Microsoft Azure. 
- It enables the **publishing and subscribing to events from various sources**, allowing reactive and event-driven architectures.

---
# [Azure Data Lake Storage](https://learn.microsoft.com/en-us/azure/storage/blobs/data-lake-storage-introduction)

- Used for storing and processing large amounts of unstructured and structured data.
- Used for transferring data between on-premises and cloud environments
- Used for **managing** and **scaling** data processing pipelines
- Provides a scalable and secure data lake solution for big data analytics and storage.

---

# [Azure Logic Apps](https://learn.microsoft.com/en-us/azure/logic-apps/logic-apps-overview)

 - Used for **building** and **managing** **serverless** workflows and integrations
 - Provides a visual designer and connectors to integrate and automate processes across different systems.

---
# [Azure Databricks](https://azure.microsoft.com/en-us/products/databricks)

-  Used for **collecting, analyzing, and visualizing data** from various sources
-  Used for **big data analytics** and **machine learning**
- Provides a collaborative and Apache Spark-based analytics platform for **big data processing**.

---
# [Azure Synapse Analytics](https://learn.microsoft.com/en-us/azure/synapse-analytics/overview-what-is)

- Used for **big data analytics** and **data warehousing**
- Combines enterprise data warehousing, big data processing, and data integration into a unified platform.

---

# [Azure App Service](https://learn.microsoft.com/en-us/azure/app-service/overview)

- Used for hosting web applications in Azure

---

# [Azure Event Hubs](https://learn.microsoft.com/en-us/azure/event-hubs/event-hubs-about)

- A **big data streaming** platform and **event ingestion** service to receive and process millions of events per second
- Used to ingest, buffer, store, and process your stream in real time to get actionable insights
- Partitioned consumer mode => Enabling multiple applications to process the stream concurrently and letting you control the speed of processing

---
# [Azure DevTest Labs](https://learn.microsoft.com/en-us/azure/devtest-labs/devtest-lab-overview)

- Azure DevTest Labs is used to manage VMs for testing, including configuration, provisioning, and automatic de-provisioning. => **Ensure the new app works across various OSes**

---
# Azure ML

-  Help us **generate high probability predictions**.

---
# [Azure Media Services](https://learn.microsoft.com/en-us/azure/media-services/latest/media-services-overview)

- Definition: A cloud-based platform that enables you to build solutions that achieve broadcast-quality video streaming, enhance accessibility and distribution, analyze content, and much more.

- **Zone-redundant** is the default redundancy configuration
- Components:
	- **Control Plane** from ARM of Media Services **works as normal** during AZ fault
	- **Key delivery** works as normal
	- **Jobs** are rescheduled in another AZ
- Recommended storage configuration for media data: ZRS, GZRS

```ad-warning
Calling `reset` on a Live Event is **NOT** supported during an Availability Zone fault.
```

- Using other Azure services for high availability streaming and encoding offers these benefits:
	- Redundancy
	- Health monitoring
	- Load balancing

---
# [Azure Container App](https://learn.microsoft.com/en-us/azure/container-apps/overview)

- **Fully managed** environment that enables you to **run microservices and containerized applications** on a **serverless** platform

![[Pasted image 20231022123427.png]]

- Distinctive features:
	- Support for service discovery + Traffic splitting
	- Scale based on **traffic** and **event sources** like queues
	- Support long-running processes and background tasks

---
# [Azure Batch](https://learn.microsoft.com/en-us/azure/batch/batch-technical-overview)

- A **platform service** for running **large-scale parallel and high-performance computing (HPC) applications** efficiently in the cloud

---
# [Static Web Apps](https://learn.microsoft.com/en-us/azure/static-web-apps/overview)

- Fully managed service that **automatically builds and deploys full-stack web apps** from a code repository. 
- **Simplify** and **streamline** the development of modern web applications.
