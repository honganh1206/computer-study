
## Explore the staging environment

- Choose separate deploy slots instead of the production one in the **Standard/Premium/Isolated** plan tier
- Benefits:
	- Validate app changes before production deployment
	- Ensure all instances of the slot are warmed up before swapped into production => Eliminate downtime
	- Re-swap the slot if there is any issue

## Examine slot swapping

- When swapping slots, App Service completes the following steps:
	1. Apply settings to the target slots
	2. Wait for every instance in the source slot to complete its restart => Revert all changes if any instance fail to restart 
	3. Trigger local cache initialization if local cache is enabled + Wait until **each** instance returns any HTTP response
	4. Trigger application initialization if auto swap is enabled with custom warm-up
	5. Swap the two slots if all instances of the **source** slot are warmed up => The target/production slot now has the warmed-up instance from the source slot
	6. The source slot (with the pre-swap instance) can now perform the same operation from 1 to 4

## Swap deployment slots

### Ways to swap

- Manual swap
	- Swap with preview/multi-phase swap
- Auto swap

### Additional actions

- Specify custom warm-up
- Roll back and monitor a swap


## Route production traffic automatically

- 2 steps to route traffic to non-production slot:
	1. Select **Deployment slots** inside App Service
	2. Choose the percentage of traffic you want to route

=> Check cookie `x-ms-routing-name` to see which slot your session is routed to 


## Route production traffic manually

- Allow user to opt out of your beta app:

```html
<a href="<webappname>.azurewebsites.net/?x-ms-routing-name=self">Go back to production app</a>
```