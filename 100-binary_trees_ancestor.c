#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancestor = first;
	while (ancestor != NULL)
	{
		if (binary_tree_is_descendant(ancestor, second))
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_descendant - Checks if a node is a descendant of another
 * @ancestor: A pointer to the ancestor node
 * @node: A pointer to the potential descendant node
 *
 * Return: 1 if node is a descendant of ancestor
 */
int binary_tree_is_descendant(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	if (ancestor == NULL)
		return (0);

	while (node != NULL)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}

	return (0);
}
