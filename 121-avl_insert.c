#include "binary_trees.h"

/**
 * balance_tree - Balances the AVL tree after insertion
 * @tree: double pointer to the root node of the AVL tree
 * @parent: parent node of the current working node
 * @value: value to insert into the AVL tree
 *
 * Return: pointer to the new root after balancing
*/
avl_t *balance_tree(avl_t **tree, avl_t *parent, int value)
{
	int bfactor = binary_tree_balance(*tree);

	if (bfactor > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
		(*tree)->parent = parent;
	}
	else if (bfactor < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
		(*tree)->parent = parent;
	}
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		(*tree)->parent = parent;
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
		(*tree)->parent = parent;
	}

	return (*tree);
}
/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: double pointer to the root node of the AVL tree to insert into
 * @parent: parent node of the current working node
 * @new: double pointer to store the new node
 * @value: value to insert into the AVL tree
 *
 * Return: pointer to the new root after insertion, or NULL on failure
*/
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
							avl_t **new, int value)
{
	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	return ((avl_t *)balance_tree(tree, parent, value));
}


/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: double pointer to the root node of the AVL tree to insert into
 * @value: value to insert into the AVL tree
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
