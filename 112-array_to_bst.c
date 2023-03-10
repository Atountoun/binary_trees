#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 *
 * if a value of the array is already present in the tree, the value is ignored
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (!array)
		return (NULL);

	root = NULL;
	i = 0;
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}

	return (root);
}
