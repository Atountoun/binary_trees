#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the uncle node
 *
 * Return: pointer to the uncle node of @node, if @node is NULL or
 * if @node has no uncle, NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle, *grandfather;

	uncle = NULL;
	if (!node || !node->parent || !node->parent->parent)
		return (uncle);
	grandfather = node->parent->parent;
	if (grandfather->left == node->parent)
		uncle = grandfather->right;
	else
		uncle = grandfather->left;

	return (uncle);
}
