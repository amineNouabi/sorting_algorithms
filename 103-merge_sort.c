#include "sort.h"

/**
 * print_sec - Prints a section of an array
 * @str: a string ([left] or [right] or [Done])
 * @array: the array
 * @start: the starting index (from)
 * @end: the ending index (to)
 */

void print_sec(char *str, int *array, size_t start, size_t end)
{
	size_t i;

	printf("[%s]:", str);
	for (i = start; i <= end; i++)
	{
		printf(" %d", array[i]);
		if (i < end)
			printf(",");
	}
	printf("\n");
}

/**
 * merge_sort - initialize the sorting
 * @array: the array
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (array && size > 1)
		top_down_merge(array, 0, size - 1);
}

/**
 * top_down_merge - the function that splites the array for merging
 * @array: the array
 * @left: the beginning of the subarray
 * @right: the end of the subarray
 */

void top_down_merge(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		if (mid && ((right - left) % 2) == 0)
			mid--;

		top_down_merge(array, left, mid);
		top_down_merge(array, mid + 1, right);

		printf("Merging...\n");
		print_sec("left", array, left, mid);
		print_sec("right", array, mid + 1, right);

		merge(array, left, right);
		print_sec("Done", array, left, right);
	}
}

/**
 * merge - this function merges the splited array
 * @array: the array
 * @left: the start of the subarray
 * @right: the end of the subarray
 */

void merge(int *array, size_t left, size_t right)
{
	size_t i, j, k, new_size, new_mid;
	int *tmp_array = malloc(sizeof(int) * (right - left + 1));

	if (tmp_array == NULL)
		return;

	new_size = 0;
	for (i = left; i <= right; i++, new_size++)
		tmp_array[new_size] = array[i];

	i = left, new_size--;
	new_mid = new_size / 2;
	if (new_mid == 0 || (new_mid != 0 && new_size % 2))
		new_mid++;
	for (j = 0, k = new_mid; j < new_mid && k <= new_size; i++)
	{
		if (tmp_array[j] <= tmp_array[k])
			array[i] = tmp_array[j], j++;
		else
			array[i] = tmp_array[k], k++;
	}

	while (j < new_mid)
		array[i++] = tmp_array[j++];
	while (k <= new_size)
		array[i++] = tmp_array[k++];

	free(tmp_array);
}
