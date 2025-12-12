# Binary search tree

- For every node, the nodes to its left are **smaller** in value, while the nodes on the right are **larger** in value

![[Pasted image 20231220165807.png]]

- Searching for Maggie by following the **alphabetical order** as a way to comparing nodes' values
	- Target value < Current node's value => Move to **left** child
	- Target value > Current node's value => Move to **right** child
- How: Start at root (David) => Go toward the right (Manning as the heavier value) => Go to the left (Maggie comes before Manning - lighter value)
- Runtime
	- $O(\log n)$ - Average case
	- $O(n)$ - Worst case

![[Pasted image 20231220170439.png]]

---

# Inverted indexes

![[Pasted image 20231220172620.png]]

![[Pasted image 20231220172159.png]]


- Build a hash table
	- Keys as the words inside the pages
	- Values are pages each word appears on

---

# The Fourier transform

- Explanation: Given a smoothie, the Fourier transform will tell you the **ingredients in the smoothie**

---

# Parallel algorithms

- Laptops and computers now come with multiple cores => To make your algorithms faster, you need to **change them to run in parallel across all the cores at once**

```ad-warning
The time gains from parallel algorithms are NOT linear

```

- Reasons for the non-linear time gains:
	- Overhead of managing the parallelism
	- Load balancing

---

# The Distributed Algorithm and `MapReduce`

- Distributed algorithms are great when **you have a lot of work to do** and **want to speed up the time required to do it**.

## The `map` function

- The `map()` function takes an array and applies the same function to each item in the array

![[Pasted image 20231220212614.png]]

```python
arr1 = [1,2,3]
arr2 = map(lambda x: 2 * x, arr1*)
>>> [2,4,6]
```

## The `reduce` function

- Reduce the whole list of items down to one item

![[Pasted image 20231220212624.png]]

```python
arr1 = [1,2,3]
reduce(lambda x,y: x+y, arr1)
>>> 6
```

---

# Bloom filters & HyperLogLog

- Check if a new item belongs in a very large set

## Bloom filters

- BFs are **probabilistic data structures** that *might give a wrong answer but the answer is probably correct*
	- False positives are **possible** (Google might say, “You’ve already crawled this site,” even though you haven’t.)
	- False negatives are **NOT possible** (f the bloom filter says, “You haven’t
crawled this site,” then you definitely haven’t crawled this site.)

- Benefits
	- Take little space
	- Great when you **do not need an exact answer**

## HyperLogLog

- **Approximate** the number of unique elements in a set
- Benefits
	- Use little memory
	- Give you a near exact answer

---

# The Secure Hash Algorithm (SHA) function

## Comparing files

- While the hash function for hash tables goes from **string to array index**, SHA is a **hash function** that given an input as a string, it returns a hash (as a short string) for the input string


![[Pasted image 20231222165424.png]]

- You can compare files by **calculating the SHA hashes and compare them**

![[Pasted image 20231222165504.png]]


## Comparing passwords

- Passwords in the database are always hashed
- Your input password will also be hashed then checked with the one in the database

![[Pasted image 20231222165759.png]]


```ad-warning
You cannot get the original string from the hashes
![[Pasted image 20231222165927.png]]
```

---

# Locality-sensitive hashing

- *Simhash* generates a hash that is **only a little different** => Simhash is useful when you want to check for similar items.

---

# Diffie-Hellman key exchange

- Answer the question: **"How do you encrypt a message so it can only be read by the person you sent the message to?"**
- How it works
	- Create two keys: Public key and Private key
	- Encrypt your message using the public key
	- The receiver can only decrypt the message using the private key
- DH solves both problems:
	- Both parties don’t need to know the cipher. So we don’t have to meet and agree to what the cipher should be.
	- The encrypted messages are extremely hard to decode.

---

# Linear programming

- Used to **maximize something given some constraints**.


```ad-important
All the graph algorithms can be done through linear programming instead.

```
