#include "sort.h"

/**
 * quick_sort - Initializes the sorting
 * @array: The array
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		sort_quick_Lomuto(array, 0, size - 1, size);
}

/**
 * sort_quick_Lomuto - Sorts The array using quick sort algorithm
 * @array: The array
 * @left: The starting index of a subarray or the array
 * @right: The ending index of the a subarray or the array
 * @size: The size of the array
 */

void sort_quick_Lomuto(int *array, size_t left, size_t right, size_t size)
{
	if (left < right)
	{
		size_t i = left, j = left;
		int pivot = array[right];

		while (j < right)
		{
			if (array[j] <= pivot)
			{
				if (i != j)
				{
					swap_int(&array[i], &array[j]);
					print_array(array, size);
				}
				i++;
			}
			j++;
		}

		if (i != right)
		{
			swap_int(&array[i], &array[right]);
			print_array(array, size);
		}

		if (i > 0)
			sort_quick_Lomuto(array, left, i - 1, size);
		sort_quick_Lomuto(array, i + 1, right, size);
	}

}

/**
 * swap_int - This function swaps two integers
 * @a: The first integer
 * @b: The second integer
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
