#include "binary_trees.h"


/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root nodeof the tree to measure.
 *
 * Return: The height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is complete - checks if a binary tree is complete recursively
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @height: height of the tree
 *
 * Return: 1 if the tree is complete
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t height)
{
	if (tree == NULL)
		return (1);

	if (index >= height)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, height) &&
		is_complete(tree->right, 2 * index + 2, height));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the roo node of the tree
 *
 * Return: 1 if the tree is complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
        size_t height = binary_tree_height(tree);

        return (is_complete(tree, 0, height));
}
