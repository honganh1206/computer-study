def get_triag_num(N):
    if N == 0 or N == 1:
        return 1
    return get_triag_num(N - 1) + N


print(get_triag_num(3))
