#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	const binary_tree_t *ancestor_f = first, *ancestor_s = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ancestor_f != ancestor_s)
	{
		ancestor_f = ancestor_f->parent;
		ancestor_s = ancestor_s->parent;

		if (ancestor_f == NULL && ancestor_s == NULL)
			return (NULL);

		if (ancestor_f == NULL)
			ancestor_f = second;

		if (ancestor_s == NULL)
			ancestor_s = first;
	}

	return ((binary_tree_t *) ancestor_f);
}
