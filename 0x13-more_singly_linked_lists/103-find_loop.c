#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tort, *har;

	if (head == NULL || head->next == NULL)
		return (NULL);

	tort = head->next;
	har = (head->next)->next;

	while (har)
	{
		if (tort == har)
		{
			tort = head;

			while (tort != har)
			{
				tort = tort->next;
				har = har->next;
			}

			return (tort);
		}

		tort = tort->next;
		har = (har->next)->next;
	}

	return (NULL);
}

