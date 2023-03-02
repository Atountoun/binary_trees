#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to measure the
 * depth
 *
 * Return: the depth of the tree or 0 if @tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
