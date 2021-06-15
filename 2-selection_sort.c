#include "sort.h"

/**
* swap - this function swaps the two integers.
*
*@a: first integer number.
*
*@b: second integer number.
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* selection_sort -  sorts an array of integers in ascending order
*		using the Selection sort algorithm
*
*@array: array of integers.
*
*@size: size of array.
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	unsigned int min_index;
	size_t n = size;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		swap(&array[min_index], &array[i]);
		print_array(array, n);
	}
}
