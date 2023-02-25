#!usr/bin/python3
""" Determines if all boxes can be opened """

def canUnlockAll(boxes):
    if boxes == None:
        return False

    unlocked = [0]

    for key in unlocked:
        for k in boxes[key]:
            if k not in unlocked:
                if k < len(boxes):
                    unlocked.append(k)


    if len(unlocked) == len(boxes):
        return True

    else:
        return False
