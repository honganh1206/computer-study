---
id: Writing tools for agents
aliases: []
tags: []
---

[Link](https://www.anthropic.com/engineering/writing-tools-for-agents)

## Choosing the right tools for agents

Make sure _each tool you build has a clear, distinct purpose_.

Tools should enable agents to subdivide and solve tasks in much the same way that a human would.

Too many tools or overlapping tools can also distract agents from pursuing efficient strategies. Careful, selective planning of the tools you build (or don’t build) can really pay off.

## Namespacing your tools

Namespacing (grouping related tools under common prefixes) can help delineate boundaries between lots of tools For example, namespacing tools by service (e.g., asana_search, jira_search) and by resource (e.g., asana_projects_search, asana_users_search), can help agents select the right tools at the right time.

> Selecting between prefix- and suffix-based namespacing to have non-trivial effects on tool-use evaluations.

## Returning meaningful context from your tools

Tool implementations should take care to return only high signal information back to agents.

For example, fields like `name`, `image_url`, and `file_type` are much more likely to directly inform agents’ downstream actions and responses.

Even your tool response structure—for example XML, JSON, or Markdown—can have an impact on evaluation performance: there is no one-size-fits-all solution.

-> This is because _LLMs are trained on next-token prediction and tend to perform better with formats that match their training data_.

## Optimizing tool responses for token efficiency

Quality of context is important, but so is quantity of context.

We suggest implementing some combination of pagination, range selection, filtering, and/or truncation with sensible default parameter values for any tool responses that could use up lots of context.

E.g., for Claude Code, we restrict tool responses to 25,000 tokens by default.

## Prompt-engineering your tool descriptions

 Avoid ambiguity by clearly describing (and enforcing with strict data models) expected inputs and outputs. In particular, input parameters should be unambiguously named: instead of a parameter named `user`, try a parameter named `user_id`.