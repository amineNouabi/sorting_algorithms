#include "sort.h"

/**
 * swap_int - This function swaps two integers
 * @a: the first integer
 * @b: the second integer
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - This function sorts an array using selection sorting
 * @array: The array to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, i, j;
	int min, flag;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		min = array[i], idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
				min = array[j], idx = j;
			if (array[j] < array[j - 1])
				flag = 1;
		}
		if (flag == 0)
			break;
		swap_int(&array[idx], &array[i]);

		if (i != idx)
			print_array(array, size);
	}
}
