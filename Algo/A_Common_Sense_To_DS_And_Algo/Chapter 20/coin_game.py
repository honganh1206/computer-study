def game_winner(num_coins, current_player="you"):
    if num_coins <= 0:
        return current_player
    if current_player == "you":
        next_player = "them"
    elif current_player == "them":
        next_player = "you"

    if (
        game_winner(num_coins - 1, next_player) == current_player
        or game_winner(num_coins - 2, next_player) == current_player
    ):
        return current_player
    else:
        return next_player

'''
The pattern here is that starting with 1 coin, every third number gives victory to the opponent
So if we take the number of coins and subtract 1, if the remaining number is divisible by 3, then "them" is the winner
'''
def game_winner_2(num_coins):
    if (num_coins - 1) % 3 == 0:
        return "them"
    else:
        return "you"

print(game_winner(10))
