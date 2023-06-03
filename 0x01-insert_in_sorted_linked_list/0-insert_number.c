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

	element = malloc(sizeof(element));
	if (element == NULL)
		return NULL;

	ttmp = malloc(sizeof(tmp));
	if (ttmp == NULL)
		return NULL;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return NULL;

	if (head == NULL)
	{
		*head = element;
		element->n = number;
	}

	tmp = *head;

	while (tmp->next != NULL)
	{
		if ((tmp->n < number) && (tmp->next->n > number))
		{
			ttmp = tmp->next;
			tmp->next = element;
			element->n = number;
			element->next = ttmp;
		}
		else if ((tmp->n < number) && (tmp->next == NULL))
		{
			tmp->next = element;
			element->next = NULL;
			element->n = number;
		}
		else
			tmp = tmp->next;
	}

	return element;
}
