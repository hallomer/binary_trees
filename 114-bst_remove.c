#include "binary_trees.h"

/**
 * find_inorder_successor - Returns the minimum value of a BST
 * @root: pointer to the root node of the BST to search
 *
 * Return: minimum value
*/
bst_t *find_inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_del - Deletes a node from a binary search tree
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to delete from the BST
 *
 * Return: pointer to the new root node after deletion
*/
bst_t *bst_del(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;

		else if (parent != NULL)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;

		free(node);

		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;

		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;

		free(node);

		return (parent == NULL ? node->left : root);
	}

	successor = find_inorder_successor(node->right);
	node->n = successor->n;

	return (bst_del(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree
 * @root: pointer to the root node of the BST to remove
 * @node: pointer to the current node in the BST
 * @value: value to remove from the BST
 *
 * Return: pointer to the root node after deletion
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node == NULL)
		return (NULL);

	if (node->n == value)
		return (bst_del(root, node));

	if (node->n > value)
		return (bst_remove_recursive(root, node->left, value));

	return (bst_remove_recursive(root, node->right, value));
}

/**
 * bst_remove - Removes a node from a binary search tree
 * @root: pointer to the root node of the BST to remove
 * @value: value to remove in the BST
 *
 * Return: pointer to the new root node after deletion
*/
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
