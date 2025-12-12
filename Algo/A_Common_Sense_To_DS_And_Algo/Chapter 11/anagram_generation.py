def generate_anagram(string):
    # Base case: 1 char => return the only char
    if len(string) == 1:
        return [string[0]]
    collection = []
    # Find all anagrams of the substring from the 2nd char until the end
    substring_anagrams = generate_anagram(string[1:])

    # Iterate over each substring
    for substring_anagram in substring_anagrams:
        # Iterate over each index/char of the substring
        # Insert the string[0] at the end too
        for index in range(len(substring_anagram) + 1):
            # Make a copy of each substring as strings are immutable in Python
            copy = str(substring_anagram)
            # Insert the 1st char of our string into the space between each char of the substring anagram
            # Then add this new string into the collection
            collection.append(copy[:index] + string[0] + copy[index:])

    return collection


print(generate_anagram("abc"))
