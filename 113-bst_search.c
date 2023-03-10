#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 *
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to @value,
 * NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	temp = (bst_t *) tree;
	while (temp)
	{
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else
			return (temp);
	}

	return (NULL);
}
