#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort - sort and print an array
 *
 * @array: array to check
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	mergeSort(array, 0, size);
	print_array(array, size);
}

/**
 * mergeSort - sort and merge an array
 *
 * @array: array to check
 * @index: index to start
 * @size: size of the array
 *
 * Return: nothing
 */
void mergeSort(int *array, size_t index, size_t size)
{
	size_t mid = size / 2;

	mergeSort(array, index, mid);
	mergeSort(array, mid + 1, size);
	merge(array, index, mid, size);
}

/**
 * merge - merge an array
 *
 * @arr: array to check
 * @index: index to start
 * @mid: middle of the array
 * @last: last index aka size
 *
 * Return: nothing
 */
void merge(int *arr, int index, int mid, int last)
{
	int i, j, k;
	int n1 = mid - index + 1;
	int n2 = last - mid;
	int *R = arr;
	int *L = arr;

	for (i = 0; i < n1; i++)
		L[i] = arr[last + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = index;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

