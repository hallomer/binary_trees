#include "binary_trees.h"

/**
 * insert_node - Inserts a new node into the BST
 * @root: pointer to the root node of the BST
 * @new_node: pointer to the new node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
*/
bst_t *insert_node(bst_t *root, bst_t *new_node)
{
	bst_t *tmp = root;

	while (tmp)
	{
		if (new_node->n < tmp->n)
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
		else if (new_node->n > tmp->n)
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
		{
			free(new_node);
			return (NULL);
		}
	}

	return (NULL);
}

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (tree == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	return (insert_node(*tree, new_node));
}
