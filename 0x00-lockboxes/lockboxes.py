#!/usr/bin/python3

""" """

def canUnlockAll(boxes):

    keys = []
    box = 0

    for box in boxes:
        for key in boxes[box]:
            keys.append(key)
            print (keys)

        for key in keys:
            for key in :
                box = key
                break
            elif key not in range(0, len(boxes)):
                return False
    return True
