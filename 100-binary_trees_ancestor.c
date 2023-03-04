#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * match_ancestor - checks if a node matches with ancestors of a given node
 *
 * @ancestors: pointer to a list of nodes that represent ancestors of a given
 * node
 * @node: node to search in @ancestors
 *
 * Return: 1 if @node is present in @ancestors, else 0
 */
int match_ancestor(binary_tree_t **ancestors, const binary_tree_t *node)
{
	binary_tree_t **copy;
	int i;

	copy = ancestors;
	i = 0;

	while (copy[i])
	{
		if (copy[i] == node)
			return (1);
		i++;
	}
	return (0);
}

/**
 * count_ancestors - counts the number of parent nodes of a given node
 *
 * @node: the node to count the ancestors
 *
 * Return: the number of ancestors of @node
 */
int count_ancestors(const binary_tree_t *node)
{
	int count;

	count = 0;
	while (node->parent)
	{
		count += 1;
		node = node->parent;
	}
	return (count);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of @first and @second
 * of NULL if they don't have
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second
)
{
	binary_tree_t *ancestor;
	binary_tree_t **first_ancestors;
	int count_first_ancestors, i;

	ancestor = NULL;
	count_first_ancestors = count_ancestors(first) + 1;
	first_ancestors = (binary_tree_t **) malloc(
			count_first_ancestors * sizeof(binary_tree_t *)
			);
	if (!first_ancestors)
		return (NULL);
	i = 0;
	first_ancestors[i++] = (binary_tree_t *) first;
	while (first->parent)
	{
		first_ancestors[i++] = (binary_tree_t *) first->parent;
		first = first->parent;
	}
	first_ancestors[i] = (binary_tree_t *) first;
	while (second)
	{
		if (match_ancestor(first_ancestors, second) == 1)
		{
			ancestor = (binary_tree_t *) second;
			break;
		}
		second = second->parent;
	}
	free(first_ancestors);

	return (ancestor);
}
