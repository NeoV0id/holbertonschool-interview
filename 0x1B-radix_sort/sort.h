#ifndef __SORT_H__
#define __SORT_H__

#include <stdbool.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void csort2(int *array, int **buff, int size, int lsd);
void csort(int *array, int size, int lsd);
void radix_sort(int *array, size_t size);
/*bool _is_sorted(int *array, size_t size);*/

#endif /* __SORT_H__ */
