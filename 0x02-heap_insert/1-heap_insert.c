#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - insert a node according to its value
 * @root: tree on which insert the node
 * @value: value of the node to create/insert
 *
 * Return: the tree including the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t *new, *tmp;

    tmp = malloc(sizeof(binary_tree_t));
    if (tmp == NULL)
        return NULL;

    tmp = *root;

    if (tmp == NULL)
    {
        new = binary_tree_node(NULL, value);
        *root = new;
        return *root;
    }

    new = binary_tree_node(tmp, value);
    while ((tmp->left != NULL) && (tmp->right != NULL))
    {    
        if (new->n >= tmp->n)
        {
            if (tmp->parent == NULL)
                tmp = new;
            new->parent = tmp->parent;
            new->left = tmp;
            return *root;
        }
        else if ((new->n < tmp->n) && (tmp->left == NULL))
        {
            tmp->left = new;
            return *root;
        }
        tmp = tmp->left;
    }
    return NULL;
}