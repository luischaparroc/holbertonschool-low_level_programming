#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *bigger;
	int control;

	if (head == NULL)
		return (NULL);

	bigger = NULL;
	control = 0;

	while (head->next != NULL)
	{
		if (bigger == head)
		{
			control++;
			if (control == 3)
				break;
		}

		if ((long int)head->next > (long int)head && control == 0)
		{
			bigger = head->next->next;
			control = 1;
		}
		head = head->next;
	}
	if (head->next == NULL)
		return (NULL);
	return (bigger);
}
