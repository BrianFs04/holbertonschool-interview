#!/usr/bin/python3
"""pascal_triangle module"""


def pascal_triangle(n):
    """Returns the perimeter of the island described in grid"""
    lst = []
    lst_con = []

    for i in range(0, n):
        pox = lst
        if i is not 0:
            lst = [1]
        for j in range(1, i):
            lst.append(pox[j - 1] + pox[j])
        lst.append(1)
        lst_con.append(lst)
    return lst_con
