#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *
 * @list: The list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			tmp = curr->next;
			if (tmp != NULL)
				tmp->prev = prev;
			prev->next = tmp;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			prev = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
