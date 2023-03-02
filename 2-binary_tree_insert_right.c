#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of
 * another node
 *
 * if parent already has a right-child, the new node must take its
 * place and the old-right must be set as the right-child of the new node
 *
 * @parent: pointer to the parent of the node to insert
 * @value: value to store in the new node
 *
 * Return: pointer to the created node or NULL on failure or if
 * parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_node;

	if (!parent)
		return (NULL);
	new_node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;
	if (parent->right)
	{
		old_node = parent->right;
		new_node->right = old_node;
		old_node->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
