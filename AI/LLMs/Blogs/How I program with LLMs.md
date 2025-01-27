---
id: How I program with LLMs
aliases: []
tags:
  -  #LLM
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
