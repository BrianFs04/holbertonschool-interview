#!/usr/bin/python3


def canUnlockAll(boxes):

    hand = [0]

    for keys in hand:
        for boxKey in boxes[keys]:
            if boxKey not in hand and not boxKey >= len(boxes):
                hand.append(boxKey)

    if len(hand) == len(boxes):
        return True
    return False
