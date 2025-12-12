def word_builder(array):
    collection = []
    array_length = len(array)
    for i in range(0, array_length):
        for j in range(0, array_length):
            if i != j:
                collection.append(array[i] + array[j])

    return collection

print(word_builder(["a", "b", "c"]))
