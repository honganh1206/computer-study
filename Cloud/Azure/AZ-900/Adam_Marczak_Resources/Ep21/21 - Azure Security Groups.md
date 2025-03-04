# Network Security Groups

![[Pasted image 20230929161049.png]]

- Designed to **filter traffic** from outbound Azure resources to inbound ones, all located in Azure Virtual Network
- Filtering controlled by rules
- Can have **multiple inbound and outbound rules**
- Create rules by specifying
	- Source/Destination (IP addresses, service tags, application security groups)
	- Protocol (TCP, UDP, any)
	- Ports
		- 3389 - RDP
		- 22 - SSH
		- 80 - HTTP
		- 443 - HTTPS
	- Direction (inbound/outbound)
	- Priority (order of evaluation)

# Azure Security Groups

![[Pasted image 20230929162518.png]]

- **Grouping VMs** located in Azure Virtual Network
- Designed to **reduce the maintenance effort** by **assigning ASG instead of the explicit static IP address**