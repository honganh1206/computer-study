
## Examine autoscale factors

- Autoscaling performs scaling _in and out_, as opposed to scaling _up and down_.
- Autoscaling responds to changes in the environment by **adding or removing web servers** and **balancing the load between them**

### Autoscaling rules

- Autoscaling makes its decisions based on rules that you define. => **Define your autoscaling rules carefully**

### Benefits of auto-scaling

- Provide elasticity
- Improve availability + fault tolerance

### What to consider

- Not a best approach to handle long-term growth => Better manually scale the system
- Number of instances of a service => The fewer the number of instances initially, the less capacity you have to handle an increasing workload while autoscaling spins up more instances.

## Identify autoscale factors

- When the web app scales out, Azure starts new instances of the hardware defined by the App Service Plan to the app.
- To prevent runaway autoscaling, an App Service Plan has an **instance limit**.


> [!warning]
> 
> Not all App Service Plan pricing tiers support autoscaling.


### Autoscale conditions

- Azure provides 2 options for autoscaling:
	- Scale based on a metric
	- Scale to a specific instance count
- You can create **multiple autoscale conditions**

### Metrics for autoscale rules

- CPU percentage
- Memory percentage
- Disk queue length
- Http Queue Length
- Data In/Out

> [!note]
> 
> The aggregation calculation for the _Duration_ can be different from the _time grain_.


### Autoscale actions

- An autoscale action can be _scale-out_ or _scale-in_ => A scale-out action increases the number of instances, and a scale-in action reduces the instance count.
- An autoscale action has a _cool down_ period, specified in minutes. => During this interval, the scale rule won't be triggered again.

## Enable autoscale in App Service

### Best practices

- Ensure the maximum and minimum values are different and have an adequate margin between them
- Choose the appropriate statistic for your diagnostics metric => Most common is **static**
- Choose the thresholds carefully for all metric types

> [!tip] Choosing an adequate margin
> 
> We recommend choosing an adequate margin between the scale-out and in thresholds. As an example, consider the following better rule combination.
> - Increase instances by 1 count when CPU% >= 80
> - Decrease instances by 1 count when CPU% <= 60
> 
> In this case
> 1. Assume there are 2 instances to start with.
> 2. If the average CPU% across instances goes to 80, autoscale scales out adding a third instance.
> 3. Now assume that over time the CPU% falls to 60.
> 4. Autoscale's scale-in rule estimates the final state if it were to scale-in. For example, 60 x 3 (current instance count) = 180 / 2 (final number of instances when scaled in) = 90. So autoscale doesn't scale-in because it would have to scale out again immediately. Instead, it skips scaling in.
> 5. The next time autoscale checks, the CPU continues to fall to 50. It estimates again - 50 x 3 instance = 150 / 2 instances = 75, which is below the scale-out threshold of 80, so it scales in successfully to 2 instances.



> [!info] Considerations for scaling when multiple rules are configured in a profile
> 
> On _scale-out_, autoscale runs if **any** rule is met. On _scale-in_, autoscale require **all** rules to be met.


- Always select a safe default instance count
- Configure autoscale notifications

## Explore autoscale best practices

