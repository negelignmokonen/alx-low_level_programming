#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *tort, *har;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tort = head->next;
	har = (head->next)->next;

	while (har)
	{
		if (tort == har)
		{
			tort = head;
			while (tort != har)
			{
				nodes++;
				tort = tort->next;
				har = har->next;
			}

			tort = tort->next;
			while (tort != har)
			{
				nodes++;
				tort = tort->next;
			}

			return (nodes);
		}

		tort = tort->next;
		har = (har->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *buff;
	size_t nd, idx;

	nd = looped_listint_count(*h);

	if (nd == 0)
	{
		for (; h != NULL && *h != NULL; nd++)
		{
			buff = (*h)->next;
			free(*h);
			*h = buff;
		}
	}

	else
	{
		for (idx = 0; idx < nd; idx++)
		{
			buff = (*h)->next;
			free(*h);
			*h = buff;
		}

		*h = NULL;
	}

	h = NULL;

	return (nd);
}

