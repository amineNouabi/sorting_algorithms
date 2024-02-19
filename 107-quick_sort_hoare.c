#include "sort.h"

/**
 * quick_sort_hoare - Initializes the sorting
 * @array: The array
 * @size: The size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		hoare_sort(array, 0, size - 1, size);
}

/**
 * hoare_sort - Sorts The array using quick sort (Hoare) algorithm
 * @array: The array
 * @left: The starting index of a subarray or the array
 * @right: The ending index of the a subarray or the array
 * @size: The size of the array
 */

void hoare_sort(int *array, size_t left, size_t right, size_t size)
{
	if (left < right)
	{
		size_t i = left, j = right;
		int pivot = array[right];

		while (1)
		{
			while (array[i] < pivot)
				i++;
			while (j >= i && array[j] > pivot)
				j--;

			if (i > j)
				break;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++, j--;
		}

		hoare_sort(array, left, j, size);
		hoare_sort(array, j + 1, right, size);
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
