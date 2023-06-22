#ifndef __SORT_H__
#define __SORT_H__

/* Prototype */
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void mergeSort(int *array, size_t index, size_t size);
void merge(int *arr, int index, int mid, int last);

#endif /*__SORT_H__*/
