#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t swaps_count, i;

	if (!array || size < 2)
		return;

	swaps_count = 1;
	while (swaps_count)
	{
		swaps_count = i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				swaps_count += 1;
				swap_int(array + i, array + i + 1);
				print_array(array, size);
			}
			i++;
		}
	}
}

/**
 * swap_int - swaps two integers.
 * @a: first integer address.
 * @b: second integer address.
 */
void swap_int(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return;

	temp = *a;
	*a = *b;
	*b = temp;
}
