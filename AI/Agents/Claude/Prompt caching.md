[General guide](https://www.anthropic.com/news/prompt-caching)

[Build with Claude](https://docs.anthropic.com/en/docs/build-with-claude/prompt-caching)

## What we do

Keep a summarized version of the codebase in the prompt (a `.md` file at root of codebase?)

Enhance performance when calling tools for multiple rounds, where each step requires a new API call

Embed the entire document in the prompt (RAG?)

> During a multi-turn conversation (10-turn convo with a long system prompt), latency with caching is around 2.5s and cost reduction is -53%

## How prompt caching works

The system checks if a prompt prefix is already cached -> If found, use the cached version and process the full prompt if not

By default the cache has a 5-minute lifetime

## What can be cached



## Structure your prompt

Place static content (tool definitions, system instructions, context, examples) at the beginning of your prompt. Cache prefixes are created in the following order: `tools`, `system`, then `messages`.

We can define up to 4 cache breakpoints to cache different reusable sections separately

## Cache limitations

1024 tokens for Opus and Sonnet models, 2048 for Haiku models

