basketball_players = [
    {"first_name": "Jill", "last_name": "Huang", "team": "Gators"},
    {"first_name": "Janko", "last_name": "Barton", "team": "Sharks"},
    {"first_name": "Wanda", "last_name": "Vakulskas", "team": "Sharks"},
    {"first_name": "Jill", "last_name": "Moloney", "team": "Gators"},
    {"first_name": "Luuk", "last_name": "Watkins", "team": "Gators"},
]

football_players = [
    {"first_name": "Hanzla", "last_name": "Radosti", "team": "32ers"},
    {"first_name": "Tina", "last_name": "Watkins", "team": "Barleycorns"},
    {"first_name": "Alex", "last_name": "Patel", "team": "32ers"},
    {"first_name": "Jill", "last_name": "Huang", "team": "Barleycorns"},
    {"first_name": "Wanda", "last_name": "Vakulskas", "team": "Barleycorns"},
]


def get_players_both_sports(basketball_players, football_players):
    hash_table = {}
    shared_player_arr = []

    for i in range(len(basketball_players)):
        full_name = (
            basketball_players[i].get("first_name")
            + " "
            + basketball_players[i].get("last_name")
        )
        hash_table[full_name] = basketball_players[i].get("team")

    for i in range(len(football_players)):
        full_name = (
            football_players[i].get("first_name")
            + " "
            + football_players[i].get("last_name")
        )
        if full_name in hash_table.keys():
            shared_player_arr.append(full_name)

    return shared_player_arr


# print(get_players_both_sports(basketball_players, football_players))


def return_missing_num(num_arr):
    full_sum = 0
    current_sum = 0
    for n in range(1, len(num_arr) + 1):
        full_sum += n
    for n in num_arr:
        current_sum += n

    return full_sum - current_sum


# print(return_missing_num([0, 2, 3, 4]))


def calculate_greatest_profit(price_arr):
    buy_price = price_arr[0]
    greatest_profit = 0

    for price in price_arr:
        if price < buy_price:
            buy_price = price  # Buy low sell high
        elif price - buy_price > greatest_profit:
            greatest_profit = price - buy_price

    return greatest_profit


# print(calculate_greatest_profit([10, 7, 5, 8, 11, 2, 6]))


def calculate_highest_product(arr):
    greatest_num = -float("inf")
    second_greatest_num = -float("inf")
    lowest_num = float("inf")
    second_lowest_num = float("inf")

    for num in arr:
        if num >= greatest_num:
            second_greatest_num = greatest_num
            greatest_num = num
        # If second < current < greatest
        elif num > second_greatest_num:
            second_greatest_num = num

        if num <= lowest_num:
            second_lowest_num = lowest_num
            lowest_num = num
        elif num < second_lowest_num:
            second_lowest_num = num

        greatest_product_positive = greatest_num * second_greatest_num
        greatest_product_negative = lowest_num * second_lowest_num

    if greatest_product_positive > greatest_product_negative:
        return greatest_product_positive
    else:
        return greatest_product_negative


# print(calculate_highest_product([10, 7, 5, 8, 11, 2, 6]))


def sort_temperatures(arr):
    hash_table = {}
    for temp in arr:
        if temp in hash_table.items():
            hash_table[temp] += 1
        else:
            hash_table[temp] = 1

    sorted_arr = []
    # Multiply the temp by 10 to increment the temp by a whole number without floating point error
    temp = 970
    while temp <= 990:
        temp_float = temp / 10.0
        if hash_table.get(temp_float):
            count = hash_table[temp_float]
            for _ in range(count):
                sorted_arr.append(temp_float)
        temp += 1

    return sorted_arr


# print(sort_temperatures([98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]))


def check_longest_consecutive_seq(arr):
    # Sort the array
    hash_table = {}
    greatest_sequence_length = 0

    for value in arr:
        hash_table[value] = True

    for num in arr:
        # Check if there is a number that is even lower than the num we are iterating
        # if not, we start the sequence from the current num
        if hash_table.get(num - 1) is not True:
            current_sequence_length = 1
            current_num = num
            # This while loop is O(1)
            # As long as there is an incremented value of the current num in the hash table, we increment the sequence length by 1
            while hash_table.get(current_num + 1):
                current_num += 1
                current_sequence_length += 1
                # Greedily keep track of the greatest sequence length
                if current_sequence_length > greatest_sequence_length:
                    greatest_sequence_length = current_sequence_length

    return greatest_sequence_length


print(check_longest_consecutive_seq([10, 5, 12, 3, 55, 30, 4, 11, 2]))
