#include "binary_trees.h"
#include <stdlib.h>

/**
 * max - Computes the maximum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: the maximum of the two ntegers
 */
static int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * binary_tree_height - computes the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(binary_tree_height(tree->left), binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_avl - checks if binary tree is a valid AVL tree
 * @tree: pointer to the root node of the node of the tree
 *
 * Return: 1 if @tree is a valid AVL tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff;

	if (tree == NULL)
		return (0);

	height_diff = (int)(binary_tree_height(tree->left)) - (int)(binary_tree_height(tree->right));
	height_diff = height_diff >= 0 ? height_diff : -height_diff;

	if (height_diff <= 1 && binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
