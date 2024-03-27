#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binaty tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *left_child;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	left_child = tree->left;
	new_root = left_child;
	tree->left = left_child->right;

	if (left_child->right != NULL)
		left_child->right->parent = tree;

	left_child->right = tree;
	left_child->parent = tree->parent;
	tree->parent = left_child;

	return (new_root);
}
