---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
Let’s say we have **a staircase of N steps**, and **a person has the ability to climb one, two, or three steps** at a time. How many different possible “paths” can someone take to reach the top? Write a function that will calculate this for N steps.

=> **Divide and Conquer**: For an 11-step staircase, the 1st sub-problem is a 10-step staircase => The number of steps to the top is at least the sum of all the paths to stairs 10, 9, and 8 => **Base case of taking 1/2/3 steps**