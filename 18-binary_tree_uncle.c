#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of the node
 * @node: A pointer to the nde to find the uncle
 *
 * Return: A pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
	{
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
		else
			return (NULL);
	}
	else
	{
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
		else
			return (NULL);
	}
}
