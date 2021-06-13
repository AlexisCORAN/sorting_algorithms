#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
*		using the Bubble sort algorithm.
*
*@array: array of integers.
*
*@size: size of array.
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp, swapped = 0;
	size_t n = size;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, n);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
