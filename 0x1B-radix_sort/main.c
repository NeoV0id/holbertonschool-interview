#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

/**
 *
 */
int main(void)
{
	int arr[] = {8, 7, 4, 3, 0};

	if (_is_sorted(arr, sizeof(arr)) == true)
		printf("true\n");
	else
		printf("false\n");
	return (0);
}
