class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def search(self, word):
        current_node = self.root
        for char in word:
            if current_node.children.get(char):
                current_node = current_node.children[char]
            else:
                return None
        return current_node

    def insert(self, word):
        current_node = self.root
        for char in word:
            if not current_node.children.get(char):
                new_node = TrieNode()
                current_node.children[char] = new_node
            current_node = current_node.children[char]
        current_node.is_end_of_word = True

    def collect_all_words(self, node=None, prefix="", words=None):
        if words is None:
            words = []
        current_node = node or self.root
        if current_node.is_end_of_word:
            words.append(prefix)
        for key, child_node in current_node.children.items():
            self.collect_all_words(child_node, prefix + key, words)
        return wordsw

    def autocomplete(self, prefix):
        current_node = self.search(prefix)
        if not current_node:
            return None
        return self.collect_all_words(current_node)

    def get_all_keys(self, node=None, keys=None):
        if keys is None:
            keys = []

        if node is None:
            node = self.root
        # Add all keys from the current node's key-value pairs
        keys.extend(node.children.keys())

        for _, child_node in node.children.items():
            self.get_all_keys(child_node, keys)

        return keys

    def autocorrect(self, word):
        current_node = self.root
        word_found_so_far = ""
        for char in word:
            # Search the trie to find as much of the prefix as we can
            if current_node.children.get(char):
                word_found_so_far += char
                current_node = current_node.children.get(char)
            else:
                return word_found_so_far + self.collect_all_words(current_node)[0]

        return word


def test_trie():
    # Initialize a new Trie
    trie = Trie()

    # Insert words into the trie
    words_to_insert = ["cat", "car", "cart", "dog", "dove", "dorm"]
    for word in words_to_insert:
        trie.insert(word)

    # Test search method
    def test_search(trie, word):
        result = trie.search(word)
        if result is None:
            print(f"'{word}' not found in Trie.")
        else:
            print(f"'{word}' found in Trie.")

    search_tests = ["cat", "car", "cart", "dog", "dove", "dorm", "do", "cattle"]
    for word in search_tests:
        test_search(trie, word)

    # Test collect_all_words method
    def test_collect_all_words(trie):
        words = trie.collect_all_words()
        print("Words collected from Trie:", words)

    test_collect_all_words(trie)

    def test_autocomplete(trie, prefix):
        words = trie.autocomplete(prefix)
        print(f"Autocomplete for prefix '{prefix}':", words)

    autocomplete_tests = ["ca", "car", "do", "cat", "dor", "a"]
    for prefix in autocomplete_tests:
        test_autocomplete(trie, prefix)

    def test_get_all_keys(trie):
        all_keys = trie.get_all_keys()
        print(all_keys)

    test_get_all_keys(trie)

    def test_autocorrect(trie, word):
        suggestions = trie.autocorrect(word)
        print(f"Autocorrect for word '{word}':", suggestions)

    autocorrect_tests = ["dot", "dova", "dorw"]
    for word in autocorrect_tests:
        test_autocorrect(trie, word)


# Run the tests
test_trie()
