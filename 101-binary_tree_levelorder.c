#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * tree_height - calculates the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: the height or the number of different levels of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (!tree)
		return (0);
	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	return (left_h > right_h ? left_h + 1 : right_h + 1);
}

/**
 * print_level_nodes - prints the nodes at a given level of the tree
 *
 * @tree: pointer to the root node of the tree to traverse
 * @level: level of nodes to be printed
 * @func: pointer to a function used to print to value of the node
 *
 * Return: nothing
 */
void print_level_nodes(
		const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		print_level_nodes(tree->left, level - 1, func);
		print_level_nodes(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	height = tree_height(tree);
	for (level = 0; level < height; level++)
		print_level_nodes(tree, level, func);
}
