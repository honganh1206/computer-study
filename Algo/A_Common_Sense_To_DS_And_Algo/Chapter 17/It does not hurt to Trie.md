# It does not hurt to Trie

> [!summary] 3-sentence summary
> 
> - A trie contains a root node that points to any number of nodes as children, and each child node points to its own children nodes.
> - Both trie search and insertion are super efficient with $O(K)$ ($K$ as the number of character in the search string), and they both iterate over each character in a given string until reaching the “`*`” key indicating there is no child node left.
> - The core of building autocomplete function is we check if the given word has no children and if not, we recursively collect the keys of the children nodes and add the keys to the given word.

## Tries

> [!tip]
> 
>  The word trie is actually derived from the word *retrieval*.

- A kind of tree idea for text-based features such as autocomplete

### The Trie Node

- Trie is a collection of nodes that point to other nodes
- NOT a binary tree as a trie node can have **any** number of child nodes

![[Pasted image 20240721113057.png]]


- The value of the keys are trie nodes, which are children of this root node
- The children also contain hash tables and continue pointing to their children

## Storing words

- The trie stores words by turning each character of each word into its own trie node for example “ace” => the “a” key points to a child node containing a key of “c” => the “c” key points to a node containing a key of “e”

![[Pasted image 20240721114124.png|The hash table with the key “*” means we have reached the end of a word]]

![[Pasted image 20240721115033.png|New visualization format]]

### The need for asterisk

- Scenario: We have two words “bat” and “batter”, and the latter contains the former

![[Pasted image 20240721115237.png|”bat” is both a word and a prefix to “batter”]]

-  "`*`" are critical to indicate when parts of a word are also words themselves.

![[Pasted image 20240721135941.png|A trie containing “ace,” “act,” “bad,” “bake,” “bat,” “batter,” “cab,” “cat,”]]


## Trie Search

- Two flavors: 
	- Search if a string is a **complete** word
	- Search if a string is a **prefix** of a word
- How it works:

1. Begin the algorithm by pointing at the root node as the current node
2. Iterate over each character of our search string
3. See if the current node has a child with that character
4. If the current node has a child (current character as the key) => update the current node to become that child and continue iterating / If not => Return none

> [!tip]
> 
> As a hash table lookup takes $O(1)$ time, trie search takes as many steps as there are characters in our search string.


- We can describe the time complexity as $O(K)$, with $K$ as the number of characters in our search string. => The only factor that affects our algorithm’s speed is the size of our input, rather than all the available data.

## Trie Insertion

- How it works:

1. Point at the root node as the current node
2. Iterate over each character of the search string
3. While pointing to each character, look to see if the current node has a child with that character as a key 
4. If YES, update the current node to be this new node + repeat step 2
5. If NO, create a child node + update the current node to be this new node + repeat step 2
6. After inserting the final character into our new word, add a “`*`” child to the last node

![[Pasted image 20240721154515.png|Insert the new word “can” into our previous example list]]

## Building autocomplete

- `collect_all_words(node=None, word="", words=[])
	1. Start with a node whose descendants we are collecting words
	2. Add more chars as we move through the trie
	3. Return an array of collected words

=> Each recursive call will go through ALL children nodes before being added to the call stack


![[Pasted image 20240722212743.png|Reaching the base case with a new word “can” in an array]]

```
// Callstack visualization

collect_all_words(node=None, word="", words=[])
|
|-- collect_all_words(node=c, word="c", words=[])
    |
    |-- collect_all_words(node=a, word="ca", words=[])
        |
        |-- collect_all_words(node=n, word="can", words=[])
            |-- "can" added to words
        |
        |-- collect_all_words(node=t, word="cat", words=["can"])
            |-- "cat" added to words

```

> [!tip] Why does the array contain the word “can”?
> 
> - The subtle point is that the array can be passed up and down a call stack, as it remains the same object in memory even when we add a new values.
> - In some languages, the computer creates a new string instead of modifying the original string => While the call stacks have access to the original string, the array contains copies.


### A better autocomplete

- We focus on showing the most popular words from the available list => Give values to the `"*"` key

![[Pasted image 20240727110215.png|1 being the rarest kind of word and 10 being an extremely popular word]]



## Exercises

Ex1. `[tag, tan, tank, tap, today, total, we, well, went]`

Ex2. 

![[02-Areas/Algo_DataStruct/Algorithm_Study_Notes/A_Common_Sense_To_DS_And_Algo/Chapter 17/Ex2|“get,” “go,” “got,” “gotten,” “hall,” “ham,” “hammer,” “hill,” and “zebra.”]]


