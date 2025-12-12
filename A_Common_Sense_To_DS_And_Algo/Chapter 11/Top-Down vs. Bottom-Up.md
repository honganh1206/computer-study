---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

|                    | Top-Down                                                                     | Bottom-Up                                                                                  |
| ------------------ | ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| Computation order  | Start with the overall problem and recursively break it down to smaller ones | Start with the smallest problems and iteratively solve larger problems                     |
| Implementation     | Use loops to fill a table or array                                           | Use recursion with memoization to store results of sub-problems                            |
| Memory usage       | Predictable and fixed as tables or arrays of determined size are used        | More unpredictable as we use call stack and might overflow if the recursion depth is large |
| Initialization     | Need to initialize base cases in the table or array before iterating         | Handle the base cases as part of the recursive process                                     |
| Control flow       | Explicit, easier to understand and debug                                     | Implicit as the thought processes differ  when thinking as a human or as a computer        |
| Recursion overhead | No recursion overhead as we use iterators                                    | Huge overhead of the recursion depth is large                                              |
|                    |                                                                              |                                                                                            |
