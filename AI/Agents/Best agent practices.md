1. Paint-by-number programming

We put the numbers and the lines and the agent puts in the color

NO architectural decision, NO critical code with close supervision, NO completely new structure to the codebase

If we know how the code should look like, we put everything we know to the prompt-architecture, possible edge cases, constraints-and send to the agent

2. Small threads

When the context window reaches > 100k tokens, things start to get blurry.

At this point, ask the agent to do small things only. Start a new thread for the big work

3. Add new features

Writing a prompt is when *you use all of your software development knowledge*: Think about the architecture, the traps, where the code should be, refactoring, good test criteria, tradeoffs, etc.

Example of a good prompt:

```txt
I need your help implementing this: https://raw.githubusercontent.com/anthropics/anthropic-cookbook/refs/heads/main/tool_use/parallel_tools_claude_3_7_sonnet.ipynb

We have tools defined in core/src/tools/tools.ts (and the other files) and now I want to implement this batch tool. I imagine that it'll be a bit tricky to figure out the types, so I want you to deeply think about that and find a practical solution that doesn't lead to a lot of complicated types. We should start really simple and then evolve what we have.
```

4. Screenshot

The screenshot feedback works well when the changes the agent made did NOT work

5. Run the build and just fix the errors

6. Run `git diff` to make the agent check for its own errors

7. Add debug statements and ask the agent to clean it up

8. Paste screenshots

9. Explain code with diagrams (require Mermaid as a tool)

10. Read commits

A single commit contains an incredible amount of meta information. Use that raw commits to inject relevant context into a prompt

Note: Tested with online repository and it does not seem to work well (Zed). Better try with local repository

11. Search code

A keyword is helpful, but the agent is fast enough

```undefined
Where in the codebase do we define the database default so that new users have 0 invites? I think it's a database migration or something. You need to look in `server`
```

12. Tell it what I want

Be explicit

```undefined
Use git blame to tell me who wrote this component
```

13. Build one to throw one away

Don't mind the sunken cost. Code is cheap. Tell the agent to implement, it wait for some time, look at the code and decide if it is worth it

There might be times when you realize that you do NOT want the feature, or you don't know that you really want it

14. Use the git staging area

Let the agent do its thing. The safety net is always the version control.

If you see something good, ask the agent to stage it, and ask it to add something else. If the new change is not good., wipe the changes away

15. Write SQL

Tell the agent to use `psql` or tools from PostgreSQL MCP server

```undefined
Return me a list of users with the most number of threads, sorted by number of threads
```

## Amp

Use the oracle. It will call the ChatGPT model (the smarter one) for complex debugging

Use the subagents e.g., search agent (explicitly state that) to save the main agents context window tokens

