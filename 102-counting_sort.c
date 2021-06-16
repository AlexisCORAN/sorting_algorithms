#include "sort.h"

/**
* num_max - find the largest number in the array.
*
*@array: array of integers.
*
*@size: size of array.
*/

int num_max(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	
	return (max);
}

/**
* counting_sort - sorts an array of integers in ascending order
*               using the Counting sort algorithm
*@array: array of integers.
*
*@size: size of array.
*/

void counting_sort(int *array, size_t size)
{
	int i, max;
	int n = size;
	int *count, *output;

	if (array == NULL || n < 2)
		return;

	max = num_max(array, n);

	output = malloc(sizeof(int) * n);

	if (output == NULL)
		return;

	count = malloc(sizeof(int) * (max + 1));

	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < n; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = n - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
