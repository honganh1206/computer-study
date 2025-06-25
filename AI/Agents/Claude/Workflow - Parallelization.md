LLMs work simultaneously on a task and have their outputs aggregated programmatically (Can be combined with routing?)

Two key variations:

- Sectioning: Break a task into independent subtasks to run in parallel
- Voting: Running the same task multiple times to get diverse outputs

![[Pasted image 20250624174315.png]]


When? Speed up divided subtasks or need multiple perspectives or attempts for better results

Examples:

- Sectioning: Improve guardrails (One model processes input and the other screens them for inappropriate content) or automate evaluating LLM performance
- Voting: Code review or content evaluation (multiple prompts evaluating different aspects)