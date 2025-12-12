def double_array(arr, index=0):
  # Base case
  if (index >= len(arr)):
    return
  arr[index] *= 2
  print(arr)
  double_array(arr, index + 1)

double_array([1,2,3,4,5])
