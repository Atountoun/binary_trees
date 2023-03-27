#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 *
 * if tree is NULL, the created node must become the root
 * if the value is already present in the tree, it must be ignored
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *temp, *prev;

	node = (bst_t *) malloc(sizeof(bst_t));
	if (!node || !tree)
		return (NULL);

	node->left = NULL;
	node->right = NULL;
	node->n = value;

	if (!(*tree))
	{
		node->parent = NULL;
		*tree = node;
	}
	else
	{
		temp = *tree;
		while (temp)
		{
			prev = temp;
			if (value < temp->n)
				temp = temp->left;
			else if (value > temp->n)
				temp = temp->right;
			else
				return (NULL);
		}
		node->parent = prev;
		if (value < prev->n)
			prev->left = node;
		else if (value > prev->n)
			prev->right = node;
		else
			free(node);
	}

	return (node);
}
