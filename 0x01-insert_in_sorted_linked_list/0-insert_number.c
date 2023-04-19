#include "lists.h"
#include <stdlib.h>

/**
 * insert_node -  insert node in sorrted singly linked list
 * @head: ptr to the head of list
 * @number: value of node to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp;
	listint_t *ttmp;
	listint_t *element;

	if (head == NULL)
		return NULL;

	element = malloc(sizeof(element));
	if (element == NULL)
		return NULL;

	ttmp = malloc(sizeof(ttmp));
	if (ttmp == NULL)
		return NULL;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return NULL;

	element->n = number;
	tmp = *head;
	ttmp = *head;

	while (tmp->next != NULL)
	{
		if (tmp->n < element->n)
		{
			tmp = tmp->next;
			while (tmp == ttmp->next->next)
				ttmp = ttmp->next;
		}
		else
		{
			element->next = tmp;
			ttmp->next = element;

			if (ttmp == *head)
				*head = element;
			return element;
		}
	}

	return NULL;
}
