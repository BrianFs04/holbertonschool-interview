#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
import sys


def print_res():
    print("File size: {}".format(size))
    for k, v in sorted(ordered.items()):
        print("{}: {}".format(k, v))

if __name__ == "__main__":
    ordered = {}
    size = i = 0
    count = 1
    lst = [200, 301, 400, 401, 403, 404, 405, 500]
    data = sys.stdin
    try:
        for line in data:
            i += 1
            item = line.split(" ")
            try:
                st_code = int(item[-2])
            except:
                pass
            try:
                size += int(item[-1])
            except:
                pass
            try:
                if st_code in lst:
                    if ordered.get(st_code):
                        ordered[st_code] += count
                    else:
                        ordered[st_code] = count
            except:
                pass
            try:
                if i % 10 == 0:
                    print_res()
            except:
                pass
    except KeyboardInterrupt:
        print_res()
        raise
