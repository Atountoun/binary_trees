#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * bst_remove - removes a node from a BST
 *
 * if the node has two children, it must be replaced with its first
 * in-order successor
 *
 * @root: A pointer to the root node of the tree
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *parent;
	bst_t *successor;
	bst_t *current;

	current = root;
	while (current != NULL && current->n != value)
	{
		parent = current;
		if (current->n < value)
			current = current->right;
		else
			current = current->left;
	}
	if (current == NULL)
		return (root);
	if (current->left == NULL)
	{
		if (parent == NULL)
			root = current->right;
		else if (parent->left == current)
			parent->left = current->right;
		else
			parent->right = current->right;
		free(current);
	}
	else if (current->right == NULL)
	{
		if (parent == NULL)
			root = current->left;
		else if (parent->left == current)
			parent->left = current->left;
		else
			parent->right = current->left;
		free(current);
	}
	else
	{
		successor = current->right;
		parent = current;
		while (successor->left != NULL)
		{
			parent = successor;
			successor = successor->left;
		}
		current->n = successor->n;
		if (parent->left == successor)
			parent->left = successor->right;
		else
			parent->right = successor->right;
		free(successor);
	}
	return (root);
}
