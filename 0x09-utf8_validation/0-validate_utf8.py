#!/usr/bin/python3
"""validUTF8"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    bytes = 0
    for b in data:
        b = bin(b).replace('0b', '').rjust(8, '0')
        if bytes != 0:
            bytes -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
            bytes = len(b.split('0')[0]) - 1
    return True
