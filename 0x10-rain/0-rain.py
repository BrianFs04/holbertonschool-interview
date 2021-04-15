#!/usr/bin/python3
"""
rain module
"""


def rain(walls):
    """Returns: Integer indicating total amount of rainwater retained"""
    if not walls:
        return 0

    water_retained = 0

    for i in range(len(walls) - 1):
        # Finds the max element on the left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Finds the max elementh on the right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water_retained += min(left, right) - walls[i]

    return water_retained
