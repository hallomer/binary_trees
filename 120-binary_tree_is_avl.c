#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value allowed for nodes
 * @max: The maximum value allowed for nodes
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
*/
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, height_diff;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	height_diff = left_height - right_height;

	if (tree->n < min || tree->n > max)
		return (0);

	if (height_diff < -1 || height_diff > 1)
		return (0);

	return (is_avl(tree->left, min, tree->n - 1) &&
		   is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
