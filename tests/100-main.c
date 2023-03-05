#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
	binary_tree_t *ancestor;

	ancestor = binary_trees_ancestor(n1, n2);
	printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
	if (!ancestor)
		printf("(nil)\n");
	else
		printf("%d\n", ancestor->n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 70);
	root->left = binary_tree_node(root, 50);
	root->right = binary_tree_node(root, 90);
	root->left->left = binary_tree_node(root->left, 40);
	root->left->right = binary_tree_node(root->left, 60);
	root->right->left = binary_tree_node(root->right, 80);
	root->right->right = binary_tree_node(root->right, 110);
	root->right->right->left = binary_tree_node(root->right->right, 105);
	root->right->right->right = binary_tree_node(root->right->right, 120);
	root->right->left->left = binary_tree_node(root->right->left, 75);
	root->right->left->right = binary_tree_node(root->right->left, 85);
	root->left->right->left = binary_tree_node(root->left->right, 55);
	root->left->right->right = binary_tree_node(root->left->right, 65);
	root->left->left->left = binary_tree_node(root->left->left, 35);
	root->left->left->right = binary_tree_node(root->left->left, 45);

	binary_tree_print(root);

	launch_test(root->left, root->left);
	launch_test(root->right->left, root->right->right->right);
	launch_test(root->right->right, root->right->right->right);

	return (0);
}
