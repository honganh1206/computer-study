def golomb(n, memo={}):
    if n == 1:
        return 1
    return 1 + golomb(n - golomb(golomb(n - 1, memo), memo), memo)


print(golomb(5))
