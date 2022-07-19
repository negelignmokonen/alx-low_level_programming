#include <stdio.h>
#include "lists.h"
/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: pointer to the list.
 * Return: number of nodes.
 **/
size_t print_listint(const listint_t *h)
{
	const listint_t *linode = h;
	size_t incr = 0;

	while (linode)
	{
		printf("%i\n", linode->n);
		incr++;
		linode = linode->next;
	}

	return (incr);
}

