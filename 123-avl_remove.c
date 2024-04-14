#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to be removed from the tree
 *
 * Return: pointer to the new root node of the tree
*/
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *tmp;

    if (root == NULL)
        return (NULL);
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (!root->left || !root->right)
        {
            tmp = root->left ? root->left : root->right;
            if (!tmp)
            {
                tmp = root;
                root = NULL;
            }
            else
            {
                *root = *tmp;
                free(tmp);
            }
        }
        else
        {
            tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            root->n = tmp->n;
            root->right = avl_remove(root->right, tmp->n);
        }
    }
    if (root == NULL)
        return (NULL);
    root = (avl_t *)binary_tree_balance(root);
    return (root);
}