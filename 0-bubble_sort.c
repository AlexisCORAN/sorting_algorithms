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
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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
	unsigned int i, j;
	size_t n = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, n);
			}
		}
	}
}
