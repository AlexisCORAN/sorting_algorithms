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
* partition - Implementation of the Lomuto partition scheme.
*
*@array: array of integers.
*
*@size: size of array.
*
*@start: the initial index of the subset to order.
*
*@end: the final index of the subset to order.
*
*Return: The final partition index.
*/

int partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int p_index = (start - 1);
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			p_index++;
			swap(&array[p_index], &array[i]);
			if (array[p_index] != array[i])
				print_array(array, size);
		}
	}
	swap(&array[p_index + 1], &array[end]);
	if (array[p_index + 1] != array[end])
		print_array(array, size);
	return (p_index + 1);
}

/**
* recursive_sort - implementation of the quick sort algorithm recursively-
*
*@array: array of integers.
*
*@size: size of array.
*
*@start: the initial index of the array partition.
*
*@end: the final index of the array partition.
*/

void recursive_sort(int *array, size_t size, int start, int end)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, size, start, end);
		recursive_sort(array, size, start, pivot_index - 1);
		recursive_sort(array, size, pivot_index + 1, end);
	}
}

/**
* quick_sort - sorts an array of integers in ascending order
*		using the Quick sort algorithm
*
*@array: array of integers.
*
*@size: size of array.
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, size, 0, size - 1);
}
