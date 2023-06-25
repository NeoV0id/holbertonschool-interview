#ifndef __SORT_H__
#define __SORT_H__

/* Prototype */
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge_sort_holder(int *array, size_t size, int *holder);
void merge(int *holder, int *array, int mid, size_t size);

#endif /*__SORT_H__*/
