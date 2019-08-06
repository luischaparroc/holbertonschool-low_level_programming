#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *curr;
	listint_t *find_loop;

	curr = head;
	find_loop = NULL;

	while (head != NULL)
	{
		curr = head;

		if (find_loop == curr)
		{
			return (curr);
		}

		head = head->next;

		if ((long int)head > (long int)curr)
		{
			find_loop = head;
		}

		curr = curr->next;
	}

	return (NULL);
}
