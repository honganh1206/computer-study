function selectionSort(array) {
    for (let i = 0; i < array.length; i++) {
        let lowestNumberIndex = i; // set the leftmost index as the lowest for each pass-through
        for (let j = i; j < array.length; j++) {
            if (array[j] < array[lowestNumberIndex]) {
                lowestNumberIndex = j;
            }
        }
        // Swap the values
        if (lowestNumberIndex != i) {
            let temp = array[i];
            array[i] = array[lowestNumberIndex];
            array[lowestNumberIndex] = temp;
        }

        return array;
    }
}

console.log(selectionSort([5,3,7,8,9]));
