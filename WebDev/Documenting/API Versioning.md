When we implement some breaking changes, we want to ensure that we don’t do anything that will cause our API consumers to change their code.
=> The best way is to apply versioning to prevent breaking our API for the existing API consumers.

There are two common approaches:

1. Prefix all URLs with API version like `/v1/health` and `/v2/health` (More user-friendly)
2. Use `Accept` and `Content-Type` headers on requests and responses to convey API version like `Accept: application/vnd.greenlight-v1` (Purist approach)