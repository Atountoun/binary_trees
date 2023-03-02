#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * of another node
 *
 * If @parent already has a left-child, the new node must take
 * its place, and the old left-child must be set as the left-
 * child of the new node
 *
 * @parent: pointer to the parent node of the node to insert
 * @value: value to store in the new node
 *
 * Return: pointer to the new created node or NULL on failure
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_node;

	if (!parent)
		return (NULL);
	new_node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;
	if (parent->left)
	{
		old_node = parent->left;
		new_node->left = old_node;
		old_node->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
