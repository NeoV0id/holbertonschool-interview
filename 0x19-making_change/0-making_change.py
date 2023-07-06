#!/usr/bin/python3
"""
Module for fun make change - Holberton LL/BC Spe Project 0x19
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total:
    -coins is a list of the values of the coins in your possession
    -Return: fewest number of coins needed to meet total
        -If total is 0 or less, return 0
        -If total cannot be met by any number of coins you have, return -1
    """

    if total == 0:
        return 0

    newVal = total + 1
    store = {0: 0}

    for i in range(1, total + 1):
        store[i] = newVal

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            store[i] = min(store[current] + 1, store[i])

    if store[total] == total + 1:
        return -1

    return store[total]
