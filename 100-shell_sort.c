#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order using
*		the Shell sort algorithm, using the Knuth sequence
*
*@array: array of integers.
*
*@size: size of array.
*/

void shell_sort(int *array, size_t size)
{
	unsigned int interval = 1, i, j;
	int idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
	{
		interval = (interval * 3) + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > interval - 1 && array[j - interval] >= temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		idx++;
		print_array(array, size);
	}
}
