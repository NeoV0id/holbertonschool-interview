#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * tree_height - measures the height of a tree
 * @tree: tree root
 * Return: height
 */
int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (-1);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * check_left - check left part of the tree
 * @root: root of tree to check
 *
 * Return: NULL on failure or index of available node
 */
heap_t *check_left(heap_t **root)
{
	heap_t *tmp;

	tmp = malloc(sizeof(heap_t));
	if (tmp == NULL)
		return (NULL);

	tmp = *root;
	while (tmp)
	{
		if (tmp->right == NULL)
			return (tmp);
		if (tmp->left == NULL)
			return (tmp);
		tmp = tmp->left;
	}
	return (NULL);
}

/**
 * check_right - check right part of the tree
 * @root: root of tree to check
 *
 * Return: NULL on failure, index of available node
 */
heap_t *check_right(heap_t **root)
{
	heap_t *tmp;

	tmp = malloc(sizeof(heap_t));
	if (tmp == NULL)
		return (NULL);

	tmp = *root;
	while (tmp->left != NULL)
	{
		if (tmp->right == NULL)
			return (tmp);
		tmp = tmp->right;
	}
	return (NULL);
}

/**
 * swap - swap nodes according to max heap tree
 *
 * @root: root of tree to check
 * @node: node to swap
 *
 * Return: NULL on failure, swapped tree on success
 */
void swap(heap_t **root, heap_t *node)
{
	heap_t *tmp, *ttmp;

	tmp = malloc(sizeof(heap_t));
	if (tmp == NULL)
		exit(EXIT_FAILURE);

	ttmp = malloc(sizeof(heap_t));
	if (ttmp == NULL)
		exit(EXIT_FAILURE);

	tmp = *root;
	while (tmp)
	{
		while (node->n < tmp->n)
		{
			if ((tmp->parent == NULL) && (tmp->n < node->n))
			{
				tmp->parent = node->parent;
				node->left = tmp->left;
				node->right = tmp->right;
				tmp->left = NULL;
				tmp->right = NULL;
				node->parent = NULL;
				*root = node;
			}
			else if (tmp->n < node->n)
			{
				ttmp = tmp->parent;
				tmp->parent = node->parent;
				node->left = tmp->left;
				node->right = tmp->right;
				node->parent = ttmp;
				tmp->left = NULL;
				tmp->right = NULL;
			}
		}
		tmp = tmp->left;
	}
}
/**
 * heap_insert - insert a node according to its value
 * @root: tree on which insert the node
 * @value: value of the node to create/insert
 *
 * Return: the tree including the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tmp, *ttmp, *new;
	int heightl, heightr;

	tmp = malloc(sizeof(heap_t));
	if (tmp == NULL)
		return (NULL);

	ttmp = malloc(sizeof(heap_t));
	if (ttmp == NULL)
		return (NULL);

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	tmp = *root;
	new->n = value;
	heightl = tree_height(tmp->left);
	heightr = tree_height(tmp->right);

	while (tmp)
	{
		if (heightl <= heightr)
		{
			if (check_left(root) != NULL)
			{
				ttmp = check_left(root);
				ttmp->left = new;
				if (new->n > tmp->n)
					swap(root, new);
				return (new);
			}
		}
		else
		{
			if (check_right(root) != NULL)
			{
				ttmp = check_right(root);
				ttmp->right = new;
				if (new->n > tmp->n)
					swap(root, new);
				return (new);
			}
		}
		tmp = tmp->left;
	}
	return (NULL);
}
