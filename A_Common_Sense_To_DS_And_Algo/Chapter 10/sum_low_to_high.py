def sum_low_to_high(l, h):
    if l == h:
        return l
    else:
        return h + sum_low_to_high(l, h - 1)


print(sum_low_to_high(1, 4))
