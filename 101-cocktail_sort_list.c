#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *cursor;

	if (!list || !*list || !(*list)->next)
		return;

	cursor = *list;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (cursor->next)
		{
			if (cursor->n > cursor->next->n && ++swapped)
				swap_right(cursor, list);
			else
				cursor = cursor->next;
		}
		while (cursor->prev)
		{
			if (cursor->n < cursor->prev->n && ++swapped)
				swap_left(cursor, list);
			else
				cursor = cursor->prev;
		}
	}
}

/**
 * swap_right - Swaps a node with the one to its right
 * @cursor: The node to be swapped
 * @head: The head of the doubly linked list
 */
void swap_right(listint_t *cursor, listint_t **head)
{
	listint_t *next;

	next = cursor->next;
	if (cursor->prev)
		cursor->prev->next = next;
	next->prev = cursor->prev;
	if (next->next)
		next->next->prev = cursor;
	cursor->next = next->next;
	next->next = cursor;
	cursor->prev = next;

	if (cursor == *head)
		*head = next;
	print_list(*head);
}

/**
 * swap_left - Swaps a node with the one to its left
 * @cursor: The node to be swapped
 * @head: The head of the doubly linked list
 */
void swap_left(listint_t *cursor, listint_t **head)
{
	swap_right(cursor->prev, head);
}
