#!/usr/bin/python3
"""minOperations"""


def minOperations(n):
    """Calculates the fewest number of operations
    needed to result in exactly n H characters"""
    if type(n) is not int or n <= 1:
        return 0
    res = 0
    for i in range(2, n):
        while(n % i == 0):
            res += i
            n /= i
    if res is 0:
        return(n)
    return(res)
