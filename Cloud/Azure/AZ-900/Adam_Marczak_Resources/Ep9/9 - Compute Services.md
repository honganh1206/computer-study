
![[Pasted image 20230910214635.png]]

# Virtualization

![[Pasted image 20230910112322.png]]

- **Emulation** of physical machines
- Different **virtual hardware configs** + **OSes** per machine/app
- Separation of environments => Separation of concerns
	- File systems
	- Services
	- Ports
	- Middleware
	- Configs

# Azure Virtual Machines (VMs)

![[Pasted image 20230910112812.png]]

- IaaS
- **Total control** of OS and software
- Support marketplace and custom images
- Suited for
	- **Custom software with custom system configs**
	- **Lift-and-shift** scenario
- Can **run any app/scenario**
	- Web apps/services
	- Db
	- Desktop app
	- jumpboxes
	- gateways, etc

# Azure VM Scale Sets

![[Pasted image 20230910115028.png]]

- IaaS
- Set of **identical VMs**
- Built-in **auto scaling features**
- Designed for **manual + auto-scaled workloads** like web services, batch processing, etc.

# Containers

![[Pasted image 20230910115319.png]]

- Use host's OS
- **Emulate** OS vs. VMs emulate **hardware**
- Lightweight (no OS)
	- Dev effort
	- Maintenance
	- Compute & Storage reqs
- Respond quicker to demand changes
- Designed for **almost any scenario**

## Azure Container Instances

![[Pasted image 20230910115916.png]]

- Simplest + fastest way to run a container
- PaaS
- **Serverless** Containers
- Designed for
	- Small and simple web apps/services
	- Background jobs
	- Scheduled scripts

# Azure Kubernetes Service (AKS)

![[Pasted image 20230910212749.png]]

- Open-source container orchestration platform
- PaaS
- Scalable + Customizable
- Designed for **high scale container deployments**

# App Service

![[Pasted image 20230910213235.png]]

- Designed as **enterprise grade web app service** by **deploying packaged/containerized code or entire containers**
- PaaS
- Support **multiple programming languages and containers**

# Azure Functions/Function Apps

![[Pasted image 20230910214318.png]]

- PaaS
- Serverless
- Two hosting/pricing models
	- Consumption-based plan => Fit for services with unpredictable demand
	- Dedicated plan
- Designed for **micro/nano services**