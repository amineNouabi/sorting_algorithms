#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm and Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t knuth_gap, i;
	long j;

	if (!array || size < 2)
		return;

	knuth_gap = initial_knuth_gap(size);

	while (knuth_gap > 0)
	{
		i = knuth_gap;
		while (i < size)
		{
			j = i - knuth_gap;
			while (j >= 0 && array[j + knuth_gap] < array[j])
			{
				swap_int(array + j + knuth_gap, array + j);
				j -= knuth_gap;
			}
			i++;
		}
		print_array(array, size);
		knuth_gap = (knuth_gap - 1) / 3;
	}
}

/**
 * initial_knuth_gap - Computes largest knuth term for shell_sort
 *
 * @size: Number of elements.
 *
 * Return: largest knuth term that is not greater than
 * ceiled value of (@size / 3)
 */
size_t initial_knuth_gap(size_t size)
{
	size_t gap, peak;

	peak = size / 3;

	gap = 1;
	while (gap < peak)
		gap = gap * 3 + 1;

	return (gap);
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
