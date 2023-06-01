#!/usr/bin/python3

""" Given an n x n 2D matrix,
rotate it 90 degrees clockwise. """


def rotate_2d_matrix(matrix):

    N = len(matrix)

    matrix_copy = []
    copy_row = 0
    for column in range(N):
        for row in range((N - 1), -1, -1):
            if column == 0:
                matrix_copy.append([])
            matrix_copy[copy_row].append(matrix[row][column])
        copy_row += 1
    for row in range(N):
        for column in range(N):
            matrix[row][column] = matrix_copy[row][column]
