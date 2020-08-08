#!/usr/bin/python3
"""minOperations"""


def minOperations(n):
    """Calculates the fewest number of operations
    needed to result in exactly n H characters"""
    res = 0
    for i in range(2, n):
        while(n % i == 0):
            res += i
            n /= i
    return(res)
