#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * size - calculates the number of nodes of a binary tree
 *
 * @tree: pointer to the root of the tree to use
 *
 * Return: the number of nodes of @tree
 */
int size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + size(tree->left) + size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root of the tree to check
 *
 * Return: 1 if @tree is perfect, otherwise 0 or if @tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int length, is_perfect;

	length = size(tree);
	is_perfect = (length & (length + 1)) == 0;
	return (is_perfect);
}
