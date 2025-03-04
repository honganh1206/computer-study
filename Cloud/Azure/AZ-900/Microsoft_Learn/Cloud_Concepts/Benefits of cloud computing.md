# What to focus on
- Describe the benefits of high **availability** and **scalability** in the cloud.
- Describe the benefits of **reliability** and **predictability** in the cloud.
- Describe the benefits of **security** and **governance** in the cloud.
- Describe the benefits of **manageability** in the cloud.

---
# High availability

- Service availability must be guaranteed - Part of the service-level agreements (SLAs)
- Ideal uptime is 99.9%

---
# Scalability

- Focus: Adjust resources to meet demand
- Follow the Economies of scale
- Two types: Vertical and Horizontal Scaling
## Vertical scaling

- Scale up processing power to the virtual machine
## Horizontal scaling

- Deploy additional resources (VMs, containers) in accordance with the demand (Scale out/in)
---
# Reliability

- The ability to **recover from failures**
- Cloud environment could shift to a different region in case of emergency

--- 
# Predictability

- **Performance** focuses on predicting the resources needed to deliver a positive experience for your customers
	- Autoscaling: Adjust resources to meet the demand
	- Load balancing: Redirect some of the overload to less stressed area
- **Cost**: Track your resources in real time
---
# Governance & Compliance

- Set templates to meet corporate standards
- Update deployed resources to new standards

```ad-success
title: IaaS, PaaS and SaaS in terms of Security
IaaS allows you to manage OSes and installed software, while PaaS and SaaS take care of patches and maintenance automatically

```
- Cloud providers are suited to handle DDoS
--- 
# Management

## Benefits

- **Automatically scale** resource deployment based on need.
- **Deploy resources based on a preconfigured template**, removing the need for manual configuration.
- **Monitor the health** of resources and automatically replace failing resources.
- **Receive automatic alerts** based on configured metrics, so you’re aware of performance in real time.
## Ways to manage

- Through a web portal.
- Using a command line interface.
- Using APIs.
- Using PowerShell.

---
# Analysis Services
## [Achieve High Availability and Scalability](https://learn.microsoft.com/en-us/analysis-services/instances/high-availability-and-scalability-in-analysis-services?view=asallproducts-allversions)

```ad-warning
title: Analysis Services CANNOT be configured to run in an Always On availability group
The Always On feature of the relational database engine **does not extend to Analysis Services**. It is **not possible** to configure an Analysis Services instance to run in an Always On availability group.

```

- Techniques to achieve both scalability and high availability:
	- Network Load Balancing (NLB) provides **scalability** by load-balancing over **read-only databases**
	- Window Server Failover Cluster (WSFC) provides **high availability** through server redundancy and failover capability


```ad-done
title: Designing resilient applications
When designing an application to be resilient, considerations such as the **cost of downtime**, **investment in high availability**, and clearly **defined targets for uptime and downtime** should be taken into account.

```

---
# [Microsoft Azure Well-Architected Framework](https://learn.microsoft.com/en-us/azure/well-architected/)

The **reliability pillar** of the Microsoft Azure Well-Architected Framework covers these following topics:
- Reliability design principles
- Resiliency and dependencies
- Testing for reliability

```ad-note
title: Challenges cloud applications face in terms of reliability
- Complex nature of distributed systems
- Potential hardware failures
- Unavailability of external services

```

```ad-warning
title: Concerns when providing operations management support in a new environment
When organizations try to provide operations management support to workloads in new environments, they can face the challenge of d**isparate operations tooling and practices**, which can increase the cost of operations.

```
