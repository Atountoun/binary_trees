#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * _height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the
 * height
 *
 * Return: the height of the tree or 0 if @tree is NULL
 */
size_t _height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	left_h = 0;
	right_h = 0;
	if (!tree)
		return (0);
	left_h = _height(tree->left);
	right_h = _height(tree->right);

	return (left_h > right_h ? left_h + 1 : right_h + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to measure the
 * balance factor
 *
 * Return: the balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((int)_height(tree->left) - (int)_height(tree->right));
}

