#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * bst_checker - helper function used to check if a btree is a bst
 *
 * @tree: pointer to the root node of the btree
 * @min: minimum value of the value of a given node
 * @max: maximum value of the value of a given node
 *
 * Return: 1 if @tree is a bst, else 0
 */
int bst_checker(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (bst_checker(tree->left, min, tree->n - 1)
			&& bst_checker(tree->right, tree->n + 1, max));

	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is valid binary search tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if @tree is a valid BST, 0 otherwise or if @tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	return (bst_checker(tree, INT_MIN, INT_MAX));
}
