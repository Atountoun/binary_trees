#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - counts the number of nodes of a binary tree
 *
 * @tree: pointer to the root node of the tree or subtree
 *
 * Return: the number of nodes of @tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * check_complete - checks if a binary tree is complete
 *
 * @node: pointer to a node of the tree
 * @index: position of the node if the tree will be stored in an array
 * @size: the number of nodes of the tree
 *
 * Return: 1 if the tree is complete, else 0
 */
int check_complete(const binary_tree_t *node, size_t index, size_t size)
{
	if (!node)
		return (1);
	if (index >= size)
		return (0);
	return (
			check_complete(node->left, 2 * index + 1, size)
			&& check_complete(node->right, 2 * index + 2, size)
			);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise or if @tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	index = 0;

	return (check_complete(tree, index, size));
}
