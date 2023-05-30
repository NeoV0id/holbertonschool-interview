#!/usr/bin/python3
""" Check if all boxes can be opened """


def canUnlockAll(boxes):
    if boxes is None:
        return False

    unlocked = [0]

    for keys in unlocked:
        for key in boxes[keys]:
            if key not in unlocked:
                if key < len(boxes):
                    unlocked.append(key)

    if len(unlocked) == len(boxes):
        return True

    else:
        return False
