# Algorithm to find a substring


def find_needle(needle, haystack):
    needle_index = 0
    haystack_index = 0
    while haystack_index < len(haystack):
        # Check if the current position of the needle matches the current position of the haystack
        if needle[needle_index] == haystack[haystack_index]:
            # If yes, enter another loop to compare subsequent characters of both strings
            found_needle = True
            while needle_index < len(needle):
                # If there is a mismatch => break out of the inner loop
                if needle[needle_index] != haystack[haystack_index + needle_index]:
                    found_needle = False
                needle_index += 1
            # If the entire needle string matches => return true
            if found_needle:
                return True
            needle_index = 0  # If found the needle string or reaching the end of the haystack string => Reset
        haystack_index += 1 # Move to the next character of the haystack string
    return False


print(find_needle("abc", "abcde"))
