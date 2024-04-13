#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a BST
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = binary_tree_node(NULL, value), *tmp;

	if (tree == NULL || new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	tmp = *tree;
	while (tmp)
	{
		if (value < tmp->n)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				tmp->left = new_node;
				new_node->parent = tmp;
				return (new_node);
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				tmp->right = new_node;
				new_node->parent = tmp;
				return (new_node);
			}
		}
		else
			return (NULL);
	}
	return (NULL);
}
