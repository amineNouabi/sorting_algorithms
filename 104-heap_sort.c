#include "sort.h"

#define leftChild(i) (2 * i + 1)

/**
 * heap_sort - This function sort an array using heap sort algorithm
 * @array: The array
 * @size: The size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t root, child, start, end;

	if (!array && size < 2)
		return;


	start = size / 2;
	end = size;
	while (end > 1)
	{
		if (start > 0)
			start--;
		else
		{
			end--;
			swap_int(&array[end], &array[0]);
			print_array(array, size);
		}

		root = start;
		while (leftChild(root) < end)
		{
			child = leftChild(root);
			if ((child + 1 < end) && (array[child] < array[child + 1]))
				child++;

			if (array[root] < array[child])
			{
				swap_int(&array[root], &array[child]);
				print_array(array, size);
				root = child;
			}
			else
				break;
		}
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
