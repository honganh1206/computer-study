https://www.langchain.com/blog/the-anatomy-of-an-agent-harness

Agent = Model + Harness.  Harness engineering is how we build systems around models to turn them into work engines.

Models tend to use general-purpose tools like bash.

Memory: Agents durably store knowledge from one session and inject that knowledge into future sessions.

As models get more capable, some of what lives in the harness today will get absorbed into the model. Models will get better at planning, self-verification, and long horizon coherence natively, thus requiring less context injection for example.

That suggests harnesses should matter less over time.  But just as prompt engineering continues to be valuable today, it’s likely that harness engineering will continue to be useful for building good agents.
