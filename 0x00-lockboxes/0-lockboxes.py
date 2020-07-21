#!/usr/bin/python3


def canUnlockAll(boxes):

    hand = [0]

    for keys in hand:
        for boxKey in boxes[keys]:
            if boxKey not in hand:
                if boxKey >= len(boxes):
                    return False
                hand.append(boxKey)

    if len(hand) != len(boxes):
        return False
    else:
        return True
