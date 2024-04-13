#include "binary_trees.h"

/**
 * find_inorder_successor - Finds the in-order successor of a node
 * @node: pointer to the node whose successor needs to be found
 * @parent: double pointer to the parent of the successor
 *
 * Return: pointer to the in-order successor node
*/
bst_t *find_inorder_successor(bst_t *node, bst_t **parent)
{
	bst_t *successor, *tmp;

	successor = node->right;
	*parent = node;
	tmp = node->right;
	while (tmp)
	{
		*parent = successor;
		successor = tmp;
		tmp = tmp->left;
	}

	return (successor);
}

/**
 * bst_remove_node - Helper function to remove a node from a BST
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to be removed
 * @parent: pointer to the parent node of the node to be removed
 *
 * Return: pointer to the new root node of the BST after removing the node
*/
bst_t *bst_remove_node(bst_t *root, bst_t *node, bst_t *parent)
{
	bst_t *successor, *successor_parent;

	if (!node->left && !node->right)/* Case 1: Node has no children */
	{
		if (!parent)
			root = NULL; /* Removing the root node */
		else if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(node);
	}
	else if (!node->left || !node->right)/* Case 2: Node has one child */
	{
		successor = node->left ? node->left : node->right;
		if (!parent)
			root = successor; /* Removing the root node */
		else if (parent->left == node)
			parent->left = successor;
		else
			parent->right = successor;
		successor->parent = parent;
		free(node);
	}
	else	/* Case 3: Node has two children */
	{
		successor = find_inorder_successor(node, &successor_parent);

		/* Copy the successor's content to the current node */
		node->n = successor->n;

		/* Remove the successor from its current position */
		if (successor_parent != node)
			root = bst_remove_node(root, successor, successor_parent);
		else
			root->right = bst_remove_node(root->right, successor, node);
	}

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *curr, *parent;

	if (!root)
		return (NULL);

	curr = root;
	parent = NULL;

	/* Find the node to remove */
	while (curr && curr->n != value)
	{
		parent = curr;
		if (value < curr->n)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if (!curr)
		return (root); /* Value not found in the tree */

	return (bst_remove_node(root, curr, parent));
}
