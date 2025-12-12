"""
Find the maximum value that can be achieved with a given weight capacity W and a set of items each with a specified value and weight.
"""


def knapsack(values, weights, remaining_capacity, n=None, memo=None):
    if n is None:
        n = len(values)
    if memo is None:
        memo = {}
    if (n, remaining_capacity) in memo:
        return memo[(n, remaining_capacity)]
    if n == 0 or remaining_capacity == 0:
        return 0
    # Check if the weight of the current item exceeds the remaining capacity
    if weights[n - 1] > remaining_capacity:
        result = knapsack(values, weights, remaining_capacity, n - 1, memo)
    else:
        result = max(
            knapsack(values, weights, remaining_capacity, n - 1, memo), # Exclude the current item
            knapsack(values, weights, remaining_capacity - weights[n - 1], n - 1, memo)
            + values[n - 1], # Include the current item
        )
    memo[(n, remaining_capacity)] = result
    return result


values = [60, 100, 120]
weights = [10, 20, 30]
W = 50
print(knapsack(values, weights, W))  # Output: 220
