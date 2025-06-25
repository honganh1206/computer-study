Decompose a task into a sequence of steps. 

Each LLM call processes the output of the previous one

![[Pasted image 20250624172258.png]]

Programmatic checks as gates

When? Big tasks that can be decomposed easily into fixed subtasks

- Generate marketing copy then translate to other languages
- Write an outline for a document, check if the outline meets certain criteria, then write the document based on the outline

Trade off latency for higher accuracy by making each LLM call an easier task