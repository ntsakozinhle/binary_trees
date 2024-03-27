#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_util - helper function to check if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value that a node in the subtree can take
 * @max: maximum value that a node in the subtree can take
 *
 * Return: 1 if the tree is valid BST
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n) && is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is valid BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
