#include "binary_trees.h"

/**
 * bst_search - Searches for value in a BST
 * @tree: Pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		else if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
