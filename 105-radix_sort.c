#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm with Counting sort as
 * the stable sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = array_max(array, size);
	exp = 1;
	while (max / exp > 0)
	{
		counting_sort_by_exp(array, size, exp);
		print_array(array, size);
		exp *= 10;
	}
}

/**
 * array_max - Searches for max in array.
 * @array: array to search in.
 * @size: size of @array.
 *
 * Return: max element of @array
 */
int array_max(int *array, size_t size)
{
	int max;
	size_t i;

	i = 0;
	max = array[0];
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		++i;
	}
	return (max);
}

/**
 * counting_sort_by_exp - Sorts an array of integers in ascending of
 * exponent exp using the Counting sort algorithm.
 * @array: array to sort
 * @size: size of the array
 * @exp: exponent
 */
void counting_sort_by_exp(int *array, size_t size, int exp)
{
	int *counting_array, *sorted_array;
	size_t i;

	counting_array = create_counting_array_by_exp(array, size, exp);
	if (!counting_array)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}

	i = size - 1;
	while (1)
	{
		sorted_array[counting_array[(array[i] / exp) % 10] - 1] = array[i];
		counting_array[(array[i] / exp) % 10] -= 1;
		if (!i--)
			break;
	}

	i = 0;
	while (i < size)
	{
		array[i] = sorted_array[i];
		i++;
	}
	free(sorted_array);
	free(counting_array);
}


/**
 * create_counting_array_by_exp - Creates counting array for
 * Radix sort Algo by exponent.
 * @array: array of integers.
 * @size: size of the array.
 * @exp: exponent.
 *
 * Return: counting array for Counting Sort algo.
 */
int *create_counting_array_by_exp(int *array, size_t size, int exp)
{
	int *counting_array;
	size_t i;

	counting_array = malloc(sizeof(int) * 10);
	if (!counting_array)
		return (0);

	i = 0;
	while (i < 10)
		counting_array[i++] = 0;

	i = 0;
	while (i < size)
		counting_array[(array[i++] / exp) % 10]++;

	i = 0;
	while (++i < 10)
		counting_array[i] += counting_array[i - 1];
	return (counting_array);
}
