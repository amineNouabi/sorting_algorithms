#include "sort.h"
#define AC 1 /* Ascending */
#define DC 0 /* Descending */

/**
 * print_sec - This function prints a section of an array
 * @str: Merging or Result message
 * @array: The array
 * @start: the starting index (from)
 * @end: the ending index (to)
 * @size: The size of the array
 * @dir: The direction of the merge
 */

void print_sec(char *str, int *array, size_t start, size_t end,
		size_t size, int dir)
{
	size_t i, sec = end - start + 1;

	printf("%s [%ld/%ld] (%s):\n", str, sec, size, dir == AC ? "UP" : "DOWN");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * sort - This funtion sorts a section of an array using recursion
 * @a: The array
 * @left: The beginning of the subarray
 * @right: The ending of the subarray
 * @order: The order of the sort
 * @jump: The distance between elements to be compared during sorting.
 */

void sort(int *a, size_t left, size_t right, int order, size_t jump)
{
	size_t i, mid;

	if (jump == 0)
		return;
	i = left;

	mid = left + jump;
	while (i + jump <= right)
	{
		if ((a[i] > a[i + jump]) == order)
			swap_int(&a[i], &a[i + jump]);
		i++;
	}
	sort(a, left, mid - 1, order, jump / 2);
	sort(a, mid, right, order, jump / 2);

}

/**
 * init_sort - Initializes the sort of sections (helfes) of the array
 * @a: The array
 * @left: The starting index of the section
 * @right: The ending index of the section
 * @order: The order of sorting
 * @size: The total size of the array
 * @jump: The distance between elements to be compared
 *
 * Description:
 *  This function initiates the Bitonic Sort process on a specified
 *  section of the array, recursively dividing and merging the section
 *  until the entire range is sorted.
 */

void init_sort(int *a, size_t left, size_t right, int order,
		size_t size, size_t jump)
{
	size_t mid;

	jump /= 2;
	mid = left + jump;

	if (jump)
	{
		print_sec("Merging", a, left, right, size, order);

		init_sort(a, left, mid - 1, AC, size, jump);
		init_sort(a, mid, right, DC, size, jump);

		sort(a, left, right, order, jump);
		print_sec("Result", a, left, right, size, order);
	}
}

/**
 * bitonic_sort - This function sorts an array using Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array && size > 1)
		init_sort(array, 0, size - 1, AC, size, size);
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
