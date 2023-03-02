#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * if tree is NULL, do nothing
 *
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *current;

	if (tree)
	{
		current = tree;

		if (current->left)
			binary_tree_delete(current->left);
		else if (!current->right)
		{
			tree = current->parent;
			free(current);
			return;
		}
		binary_tree_delete(current->right);
		free(current);
	}
}
