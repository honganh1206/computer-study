def average_of_even_numbers(array):
  sum = 0.0
  count_of_even_numbers = 0
  for number in array:
    if (number % 2) == 0:
      sum += number
      count_of_even_numbers += 1

  return sum / count_of_even_numbers


print(average_of_even_numbers([1,2,4,6]))
