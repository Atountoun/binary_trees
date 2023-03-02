#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the
 * size
 *
 * Return: the size of the tree or 0 if @tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	if (!tree)
		return (0);
	if (tree->left)
		depth += binary_tree_size(tree->left);
	if (tree->right)
		depth += binary_tree_size(tree->right);

	return (depth + 1);
}
