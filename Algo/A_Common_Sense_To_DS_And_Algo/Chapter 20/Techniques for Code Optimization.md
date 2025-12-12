
# Techniques for Code Optimization

> [!summary] 3-sentence summary
> - Determine your current Big O and best-imaginable Big O, in that way you can trick your mind to find the best-in-between Big O for your problem.
> - Recognizing the patterns after generating examples is important to determine your best-imaginable Big O and thus coming up with the best possible algorithm.
> - Changing our current data into different data structures  is also a good approach to solve optimization problems.

## Determine your Big O

- Important to **determine the efficiency of your current code**: You cannot make an algorithm faster *if you do not know how fast it is now*

## The best imaginable Big O

- This technique could be applied to **ALL** algorithms
- The best-imaginable Big O = the Big O you could dream of for the current problem
	- E.g., If you have to print *every* element in the array, we have no choice but to process each item ($O(N)$)
- Steps summarized:
1. Determine the Big O category your current algorithm is in
2. Determine the best-imaginable Big O you could achieve
3. If the best-imaginable one > you current big O, you can now try to optimize your code as close as the best-imaginable one as possible

> [!warning]
> 
> Achieving the best-imaginable Big O is **NOT** always possible. We often optimize an algorithm to a speed that is **in between** the current Big O and the best-imaginable one

### Stretching the imagination


- Mental trick: Come up with an Amazing Big O → Think of someone that can achieve the Amazing Big O → Think you can beat them!

## Magical lookup

- Try to answer this question: If I could magically find a desired piece of information in $O(1)$ time, can I make my algorithm faster?

```ruby
# This algorithm takes O(N*M)
def connect_books_with_authors(books, authors)
	books_with_authors = []
		books.each do |book|
			authors.each do |author|
				if book["author_id"] == author["author_id"]
					books_with_authors << {title: book["title"], author: author["name"]}
			end
		end
	end
	return books_with_authors
end

# This algorithm takes O(N+M), which is much faster
# However, this increases the space constraint
def connect_books_with_authors(books, authors)
	books_with_authors = []
	author_hash_table = {}
	# Convert author data into author hash table:
	authors.each do |author|
		author_hash_table[author["author_id"]] = author["name"]
	end
	
	books.each do |book|
		books_with_authors << {"title" => book["title"], "author" => author_hash_table[book["author_id"]]}
	end
	return books_with_authors
end
```

- Again, we must choose between speed and space for optimization.

## Recognizing patterns


- Always try to **find the patterns in the problem at hand**: The pattern can help you cut through the complexity and develop a simple algorithm for the problem.

### The Coin Game

- The game: Two players are given a pile of coins. Each person is given the options to either remove 1 or 2 coins from the pile. The person who removes the LAST coin *loses*
- Pattern: Every third number gives victory to the opponent

![[Pasted image 20240831095740.png|200]]

### The Sum Swap Problem

- The problem: Two arrays of integers. Our function needs to find one number from EACH array that can be swapped so that the two array sums are equal
- Worst Big O: $O(N*M)$ | Best Big O: $O(N+M)$
- Pattern(s):
	- The larger array trades the larger number with the smaller array
	- Both arrays change by the same amount
	- The end sum is the total sum of the two arrays divided by 2

## Greedy Algorithm

- A greedy algorithm chooses **what appears to be the best option at that moment** in time.

### Array Max

```ruby
def max(array)
	# A "greedy" assumption to make the first number the greatest one
	greatest_number = array[0]
	array.each do |number|
		# Also a greedy thing is to select the best option we know at that time
		if number > greatest_number
			greatest_number = number
		end
	end
	return greatest_number
end
```

### Largest sub-section sum

- A function that accepts an array of numbers and returns the largest sum that could be computer from any *contiguous sub-section* (a section containing a series of numbers in a row) of the array
- Worst Big O: $O\left( \frac{N^2}{2} \right)$ | Best Big O: $O(N)$
- Tip: A greedy algorithm would **grab** the greatest sum at each step as we iterate over the array
- Pattern: if a negative number causes the previous sub-section’s sum to sink to a *negative number*, the streak is broken. However, if a negative number simply lowers the current sub-section’s sum and if the sum remains the positive number, the streak is thus NOT broken

### Greedy Stock Predictions

- A function that accepts an array of stock prices and determines whether there are any three prices that create an upward trend => Return true if there is an upward trend, false if not

![[Pasted image 20240831112017.png]]

- Steps:
	1. Assume the first price is the lowest
	2. Initialize the middle price (set to be infinity) to be a number guaranteed to be greater than even the highest stock price (a bit greedy here)
	3. While iterating through the array:
		1. If current price < lowest price => current price = new lowest price
		2. If current price > lowest price but current price < middle price => middle price = current price
		3. If current price > lowest and current > middle => Found the upward trend

## Change the data structure

### The anagram checker

- Scenario: Check if 2 strings are anagrams of each other => They must share the same number of characters
- Worst Big O: $O(N!)$ | Best Big O: $O(N + M)$
- Approach: Use hash table as a change of data structure instead of arrays

> [!tip]
> 
> It is not always obvious which data structures we should use, so it is better if we convert the current data into a variety of formats and see if that reveals any optimizations.