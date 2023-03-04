#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * if node is NULL or the parent is NULL, return NULL
 * if node has no sibling, return NULL
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	sibling = NULL;
	if (!node || !node->parent)
		return (sibling);
	if (node->parent->left == node)
		sibling = node->parent->right;
	else
		sibling = node->parent->left;

	return (sibling);
}
