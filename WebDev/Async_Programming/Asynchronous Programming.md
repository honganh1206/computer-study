
```ad-info
title: Definition
Async programming is a **parallel programming technique** that allows the working process to **run separately from the main application thread** => Avoid performance bottleneck + Enhance the responsiveness of our application


```

## Why? 

- We are not sending requests to the server and blocking it while waiting for the responses anymore (as long as it takes)
- How things work
	1. When we send a request to the server, **the thread pool delegates a thread to that request**
	2. When that delegated thread finishes its job, **it returns to the thread pool freeing itself for the next request** => **Callback**
	3. When there is a need for fetching data from the DB and the result needs to be sent to the requester, the thread pool provides another thread to handle that work => The delegated thread goes back to the thread pool after finishing its job

![[Pasted image 20230727215437.png]]


> [!warning] Title: Async vs Sync mode
> If we send a request to an endpoint and *it takes the application three or more seconds to process that request*, we probably won’t be able to execute this request any faster in async mode. **It is going to take the same amount of time as the sync request.**

## Async Mode

![[Pasted image 20230727233225.png]]


```cs
public async Task<IEnumerable<Company>> GetCompanies()
{
	_logger.LogInfo("Inside the GetCompanies method.");
	var companies = await _repoContext.Companies.ToListAsync();
	return companies;
}
```


- Although this method is marked with the `async` keyword, it will still execute synchronously:
	1. After logging, we continue with getting a list of companies
	2. **If our DB requires some time to process the result and return it, the `await` keyword is going to pause the whole `GetCompanies()` method execution and return an incomplete task** => The delegated thread will return to the thread pool as available for another request
	3. After the DB operation completes, the async method will resume the execution *synchronously*

#### Return types
 - `Task<TResult>` for an async method that returns **a value**
 - `Task` for an async method that **does not** return a value
	 - The `Task` has several properties that indicate **whether the operation was completed successfully or not** (`Status`, `IsCompleted`, `IsCanceled`, `IsFaulted`)
 - `void` to be used for an event handler

```ad-tip
title: When to use sync/async
Use async code wherever it is possible, but if we notice that our async code runes slower, we should switch back to the sync one.

```

## Continuation in Async programing

- All the code after awaiting an async operation is executed inside the continuation if the async operation was successful.
- We can use multiple `await` keywords in a single method
