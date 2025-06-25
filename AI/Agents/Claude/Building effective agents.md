> [!summary]
> - Build the *right* system. Start with simple prompts and evaluation, and move to multi-step agentic systems when needed
> - Core principles: Maintain simple agent's design / Prioritize transparency when the agent is planning / Carefully craft the agent-computer interface through tool documentation/prompting and testing
> - Frameworks help with getting started, but we should reduce abstractions and build with basic components

Workflows (Systems with predefined code paths) # Agents (Systems where LLMs dynamically direct their own processes and tool usage)

While workflows offer predictability and consistency for well-defined tasks, agents are better options for flexibility and model-driven decision-making

![[Pasted image 20250609114416.png]]

Three building blocks of agentic systems: Generating their own search queries (acquisition - what questions to ask), selecting appropriate tools, and determining what information to retain (curation - what answers to remember).

```
LLM: "I need to help with web development. Let me search for current Python frameworks, their performance benchmarks, and recent community adoption trends"
→ LLM evaluates results
LLM: "I'll retain the performance data and adoption metrics, but discard the installation tutorials since they're readily available elsewhere"
```

[[Workflow - Prompt chaining]]

[[Workflow - Routing]]

[[Workflow - Parallelization]]

[[Workflow - Orchestrator-workers]]

[[Workflow - Evaluator-Optimizer]]

[[Agents]]

> Tip: These common patterns are not prescriptive and we need extensive performance measure and iteration on implementations. Add complexity ONLY WHEN that improves outcomes