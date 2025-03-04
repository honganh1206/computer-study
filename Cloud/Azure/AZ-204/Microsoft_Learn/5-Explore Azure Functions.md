
## Discover Azure Functions

- A serverless solution that allows you to **write less code, maintain less infrastructure, and save on costs** without worrying about deploying and maintaining servers
- Two main components:
	- Triggers - Start code execution
	- Bindings - Simplify coding for input and output data

## Compare Azure Functions hosting options

- Three basic hosting plans for Azure Functions: Consumption/Premium/Dedicated (App service plan)

## Scale Azure Functions

- Azure Functions scales CPU and memory resources by **adding more instances of the Functions host**
- The number of instances is determined on **the number of events that trigger a function**
- Function code files are stored on **Azure Files shares on the function's main storage account**  => When you delete the main storage account of the function app, the function code files are deleted and can't be recovered


### Runtime scaling

- Azure Functions uses a component called the _scale controller_ to monitor the rate of events and determine whether to scale out or scale in.
- The scale controller uses **heuristics** (~learning by doing) for each trigger type

![[Pasted image 20240419165207.png|500]]


### Scaling behaviors

- Maximum instances: A single function app only scales out to a maximum of 200 instances + A single instance might process more than one message/request at a time => No set limit on number on concurrent executions
- New instance rate: New instances are allocated **once per second** for HTTP triggers/every 30 seconds for non-HTTP triggers