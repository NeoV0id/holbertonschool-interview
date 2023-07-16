#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _lenstr - count length of str
 *
 * @str: string to count
 *
 * Return: length
 */
int _lenstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strspy - copy string
 *
 * @str: string to copy
 *
 * Return: copied string
 */
char *_strcpy(char *str)
{
	char *new;
	int i;

	new = malloc(sizeof(char) * _lenstr(str) + 1);
	if (new == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
/**
 * create_node - create a new_node
 *
 * @str: content of the created node
 *
 * Return: the pointer of the new node
 */
List *create_node(char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	if (str == NULL)
		new_node->str = NULL;
	else
		new_node->str = _strcpy(str);
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_end - add node to the end of a list
 *
 * @list: lisst to check
 * @str: string of new node (has to be duplicated)
 *
 * Return: pointer to the new node
 */
List *add_node_end(List **list, char *str)
{
	List *new, *tmp;

	tmp = create_node(NULL);
	new = create_node(str);

	if (list == NULL)
	{
		*list = new;
		return (new);
	}

	tmp = *list;

	while (tmp->next != *list)
	{
		if (tmp->next->next == *list)
		{
			new->next = tmp->next->next;
			tmp->next->next->prev = new;
			tmp->next->next = new;
			new->prev = tmp->next;
			return (new);
		}

		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * add_node_begin - add node to beginning of a list
 *
 * @list - list to check
 * @str: string of new node
 *
 * Return: address of new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *tmp;

	tmp = create_node(NULL);
	new = create_node(str);

	if (list == NULL)
	{
		*list = new;
		return (new);
	}
	tmp = *list;

	new->next = tmp->next;
	new->prev = tmp->prev;
	tmp->next->prev = new;
	tmp->prev->next = new;
	return (new);
}
