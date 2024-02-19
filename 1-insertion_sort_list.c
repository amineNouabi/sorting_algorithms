#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list
 * @list: the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current->next)
	{

		tmp = current->next;
		flag = 1;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap(list, tmp->prev, tmp);
			print_list(*list);
			flag = 0 /* the list is not sorted */;
		}

		if (flag)
			current = current->next;
	}
}

/**
 * swap - This function swaps two nodes
 * @list: the doubly linked list
 * @a: the first node
 * @b: the second node
 */

void swap(listint_t **list, listint_t *a, listint_t *b)
{
	a->next = b->next;
	b->prev = a->prev;
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	a->prev = b;
	if (b->next)
		b->next->prev = a;
	b->next = a;
}
