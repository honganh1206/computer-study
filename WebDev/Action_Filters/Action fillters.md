
# Definition

- Offer a way to *hook into the MVC action invocation pipeline*
- Extract code that can be reused and make our actions **cleaner** and more **maintainable**
## Types of filters

- Authorization filter - Determine whether a user is authorized for a current request
- Resource filter - Run after authorization filter for caching and performance
- Action filters - Run before + after action method execution
- Exception filter - handle exceptions before the response body is populated
- Result filter - Run before + after the execution of the action method results
# Implementation

1. Create a class that inherits either from the `IActionFilter`/`IAsyncActionFilter`/`ActionFilterAttribute`
```cs
// Sync filter
public class ActionFilterExample : IActionFilter
{
	public void OnActionExecuting(ActionExecutingContext context)
	{
		// Code before action executes
	}
	public void OnActionExecuted(ActionExecutingContext context)
	{
		// Code after action executes
	}
}
// Async filter
public class AsyncActionFilterExample : IAsyncActionFilter
{
	public async Task OnActionExecutionAsync(ActionExecutingContext context,
	ActionExecutionDelegate next)
	{
		// execute any code before the action executes
		var result = await next();
		// execute any code after the action executes
	}
}
```

# Order of Invocation

![[Pasted image 20230730164839.png]]