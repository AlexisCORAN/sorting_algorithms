#include "sort.h"

/**
* counting_sort - sorts an array of integers in ascending order
*		using the Counting sort algorithm
*@array: array of integers.
*
*@size: size of array.
*/

void counting_sort(int *array, size_t size)
{
	int i;
	int n = size;
	int max = 0;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * n);

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
