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

	tmp = *head;

	if (head == NULL)
	{
		element->n = number;
		*head = element;
		return *head;
	}

	else if (tmp->n > number)
	{
		element->n = number;
		element->next = tmp;
		*head = element;
		return *head;
	}

	while (tmp != NULL)
	{
		if (tmp->next->n < number)
			tmp = tmp->next;
		else
		{
			element->n = number;
			element->next = tmp->next;
			tmp->next = element;
			return element;
		}
	}

	return element;
}
