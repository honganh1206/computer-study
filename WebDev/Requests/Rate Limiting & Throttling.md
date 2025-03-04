# Rate Limiting

```ad-info
title: Definition
Rate Limiting allows us to **protect our API against too many requests** that
can deteriorate our API’s performance

```

- To provide information about rate limiting, we use the response headers, separated between Allowed requests and Disallowed requests

## Allowed requests
The Allowed requests header contains the following information :
- X-Rate-Limit-Limit – rate limit period.
- X-Rate-Limit-Remaining – number of remaining requests.
- X-Rate-Limit-Reset – date/time information about resetting the request limit.

## Disallowed requests
- For the disallowed requests, we use a **429 status code**; that stands for too many requests.
-  This header may include the Retry-After response header and should explain details in the response body.