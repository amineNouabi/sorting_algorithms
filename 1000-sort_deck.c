#include "deck.h"
#include <string.h>

/**
 * sort_deck - This function sorts a deck using insertion sort
 * @deck: The deck
 */

void sort_deck(deck_node_t **deck)
{
	int flag;
	deck_node_t *current = *deck, *tmp;

	while (current->next)
	{
		tmp = current->next;
		flag = 1;

		while (tmp->prev && tmp->card->kind < tmp->prev->card->kind)
		{
			swap(deck, tmp->prev, tmp);
			flag = 0;
		}
		while (tmp->prev && (ToNum(tmp->card->value) < ToNum(tmp->prev->card->value)
					&& (tmp->card->kind <= tmp->prev->card->kind)))
		{
			swap(deck, tmp->prev, tmp);
			flag = 0;
		}

		if (flag)
			current = current->next;
	}
}

/**
 * ToNum - converts a string to number "1" ==> 1
 * @name: The number as string
 *
 * Return: The number as integer
 */

int ToNum(const char *name)
{
	if (!strcmp(name, "Ace"))
		return (1);
	if (!strcmp(name, "10"))
		return (10);
	if (!strcmp(name, "Jack"))
		return (11);
	if (!strcmp(name, "Queen"))
		return (12);
	if (!strcmp(name, "King"))
		return (13);

	return (name[0] - '0');
}


/**
 * swap - This function swaps two nodes
 * @list: the doubly linked list
 * @a: the first node
 * @b: the second node
 */

void swap(deck_node_t **list, deck_node_t *a, deck_node_t *b)
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
