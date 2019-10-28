#include "sort.h"
/**
 * increase_sort - move the bigger numbers to the end
 *
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *tmp, *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			tmp = aux->next;
			aux->next = tmp->next;
			tmp->prev = aux->prev;

			if (tmp->next)
				tmp->next->prev = aux;

			if (aux->prev)
				aux->prev->next = tmp;

			aux->prev = tmp;
			tmp->next = aux;

			aux = tmp;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * decrease_sort - moves the smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *tmp, *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			tmp = aux;
			aux = tmp->prev;

			aux->next = tmp->next;
			tmp->prev = aux->prev;

			if (tmp->next)
				tmp->next->prev = aux;

			if (aux->prev)
				aux->prev->next = tmp;

			aux->prev = tmp;
			tmp->next = aux;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
		}
		aux = aux->prev;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 * Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
