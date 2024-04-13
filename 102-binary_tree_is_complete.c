#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Helper function
 * @tree: pointer to the current node
 * @index: current index
 * @size: size of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
*/
int is_complete(const binary_tree_t *tree, int index, size_t size)
{
	if (tree == NULL)
		return (1);

	if ((size_t)index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = binary_tree_size(tree);

	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, size));
}
