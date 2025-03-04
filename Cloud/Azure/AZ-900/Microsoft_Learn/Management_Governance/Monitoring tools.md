# [Azure Advisor]([Introduction to Azure Advisor - Azure Advisor | Microsoft Learn](https://learn.microsoft.com/en-us/azure/advisor/advisor-overview))

- Azure Advisor **evaluates your Azure resources** and **makes recommendations** to help improve **reliability, security, and performance, achieve operational excellence, and reduce costs**.
- The recommendations are available via the Azure portal and the API, and you can set up notifications to alert you to new recommendations.

```ad-warning
Azure Advisor does not offer recommendations for AAD

```


---
# [Azure Service Health](https://learn.microsoft.com/vi-vn/azure/service-health/overview)

- Azure Service Health helps you keep track of **Azure resources and services**, both your specifically deployed resources and the overall status of Azure. 
- A combination of three separate smaller services:
	- Azure Status - Informs you of service outages in Azure
	- Service health - Provides a **personalized** view of the health of the Azure services and regions you're using
	- Resource health - Provides information about the health of your individual cloud resources such as a specific virtual machine instance
---
# [Azure Monitor](https://learn.microsoft.com/en-us/azure/azure-monitor/overview)

- Collect data on your resources, analyzing that data, visualizing the information, and even acting on the results e.g. trigger autoscaling. 
- Monitor Azure resources, your on-premises resources, and even multi-cloud resources like virtual machines hosted with a different cloud provider **on real-time** 

![[Pasted image 20230809153950.png]]

```ad-info
In Azure Monitor, an alert is considered resolved based on **the duration of the condition not being met**.

```

## [Azure Log Analytics](https://learn.microsoft.com/en-us/azure/azure-monitor/logs/log-analytics-overview)

- Log Analytics is a tool in the Azure portal that's used to **edit and run log queries against data** in the Azure Monitor Logs store.
- Actions:
	- Run a query
	- Select time range
	- Save the query
	- Export results
	- Pin results to Azure dashboard/workbook

```ad-info
Log Analytics uses the same Kusto Query Language (KQL) as Azure Data Explorer.

```


### [Azure Monitor Alerts](https://learn.microsoft.com/en-us/azure/azure-monitor/alerts/alerts-overview#types-of-alerts)

- Azure Monitor Alerts are an automated way to stay informed when Azure Monitor detects a threshold being crossed.

### Application Insights
- Application Insights is capable of **monitoring applications** that are running in Azure, on-premises, or in a different cloud environment.

## Roles with permissions to access and manage alerts information and create alert rules

- Monitoring contributor/reader

```ad-important
**Alert processing rules** determines whether an alert in Azure Monitor is considered resolved

```

---
# Azure Security Center

- Used for **monitoring** and **securing** Azure resources and workloads.
- Provides threat protection, security recommendations, and compliance management for Azure environments.

---
# [Azure Sentinel](https://learn.microsoft.com/en-us/azure/sentinel/overview)

- Helps organizations **identify and remediate security issues** in Azure by **providing intelligent security analytics and automated response capabilities**.