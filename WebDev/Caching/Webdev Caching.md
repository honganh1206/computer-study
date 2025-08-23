# Definition
- To improve performance by **eliminate the need to send requests towards the API in many cases** and **to send full responses in other cases**
- About the cache
	- The cache is a **separate component** that accepts requests from the API’s consumer.
	- It also accepts the response from the API and stores that response if they are cacheable => If the consumer requests the same response, the response in the cache should be served

# How it works
- Caching reduces the number of sent requests by using 
	- **Expiration mechanism** - Reduce network round trips  
	- **Validation mechanism** - Reduce network bandwidth
- Cache types
	- Client cache: Lives on the client (browser) => Every client/API consumer has a **private cache**
	- Gateway cache: Lives on the server and is a shared cache => Cached resources are **shared over different clients**
	- Proxy cache: Lives on the network 

```ad-info
title: Private vs. Shared cache
Supposing that we have five clients requesting the same response
- With the private cache, **every response will be served from the API instead of the cache**. However, if they request the same response again, that response will come from the private cache if its not expired
- With the shared cache, **the response from the 1st client is going to be cached**, and the other four clients will received the cached response if they request it

```

# Expiration model

```ad-info
title: Definition
The expiration model allows the server to recognize whether or not the
response has expired. As long as the response is fresh, it will be served
from the cache.

```


![[Pasted image 20230806170402.png]]

- When requesting the same response again after 2 minutes/120 seconds:
	- With private cache
![[Pasted image 20230806171047.png]]
	- With shared cache => Response from the cache is served with an additional 2 minutes when another API consumer requests:

![[Pasted image 20230806171144.png]]

# Validation model

```ad-info
title: Definition
The validation model is used to validate the freshness of the response => It checks if the response is cached and still usable

```

![[Pasted image 20230806173302.png]]

- Process #1: The client sends a request, it is not cached, and so it is forwarded to the API. Our API returns the response that contains the Etag and Last-Modified headers. That response is cached and forwarded to the client
- Process #2: The client sends the same request =>  The cache forwards that request to the API with the additional headers `If-None-Match` — which is set to the Etag value — and `If- Modified-Since` — which is set to the Last-Modified value.

![[Pasted image 20230806173437.png]]

```ad-info
title: Level of caching configuration
Configuration on the action level will override the configuration on the controller or global level. Also, the configuration on the controller level will override the global level configuration.

```
