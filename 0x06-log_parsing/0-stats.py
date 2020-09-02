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
    codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    count = 1
    data = sys.stdin
    try:
        for line in data:
            i += 1
            item = line.split(" ")
            st_code = item[-2]
            try:
                size += int(item[-1])
            except:
                pass
            try:
                if st_code in codes:
                    if ordered.get(st_code):
                        ordered[st_code] += count
                    else:
                        ordered[st_code] = count
            except:
                pass
            if i % 10 == 0:
                print_res()
        print_res()
    except KeyboardInterrupt:
        print_res()
        raise
