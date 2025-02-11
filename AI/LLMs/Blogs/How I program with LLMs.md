---
id: How I program with LLMs
aliases: []
tags:
  - #LLM
---

# How I program with LLMs

[Ref](https://crawshaw.io/blog/programming-with-llms)

## Overview

Autocomplete: Off-the-shell models are good enough

Search: For quick reference, faster and more convenient than asking old-fashioned search engines. Sometimes the LLM is wrong, but so are people

Chat-driven programming: The LLM might provide _non-deterministic service_

## Why use chat at all?

LLMs can automate the file creation, looking up libraries needed, etc. by giving the first draft with good ideas => Easier than starting from scratch

This comes in handy if your focus is on product development i.e., bouncing between environments and focusing on writing the code

## Chat-based LLMs do best with exam-style questions

Give an LLM specific objective and all background material so it can craft a well-contained code review packet

1. Avoid creating situations with so much complexity and ambiguity. Start a request with a blank slate
2. Ask for work that is easy to verify. Something like "Rewrite all of the new tests with <a new concept so that the tests are easier to read>". Redoing work is extremely cheap with LLMs

Ideal task for an LLM: **Retrieve information about common libraries**

> [!WARNING]
> ALWAYS pass an LLM's code through a compiler (well obviously) and run the tests

## Extra code structure is much cheaper?

There will be tradeoffs we make every day as we write, read and refactor code.

The same goes for LLMs: Small packages of code give LLMs complete and isolated context for a piece of work, while big packages help us with less typing to specify the context

> [!TIP]
> Use LLM code generation as a form of **specialized search** by asking it to include references
> Use imperative sentences in the prompt e.g., "In the tests, implement the simplest, most readable version of the standard code for quartiles over a fixed set of known values in a slice."

## Better tests and less DRY

There has been a more tempered approach to writing code: It is better to **reimplement a concept** if the cost of sharing the implementation is higher than the cost of implementing + maintaining separate code

Imagine you're working on a large software project that requires multiple features. The existing implementation might have most of these features, but it's too expensive or complex to manage all aspects in one package. Instead, writing smaller, focused implementations for each feature separately can reduce the overall cost and effort compared to reimplementing everything at once.

But now the tradeoffs have shifted: We now use LLMs to write the fuzz test implementation that we need but do not have the time

A future: More specialized code, fewer generalized packages, and more readable tests.

> [!TIP] How to solve a problem
> Solve a particular problem then expand slowly. Do not overgeneralize the solution.
