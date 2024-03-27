#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *right_child;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	right_child = tree->right;
	new_root = right_child;
	tree->right = right_child->left;

	if (right_child->left != NULL)
		right_child->left->parent = tree;

	right_child->left = tree;
	right_child->parent = tree->parent;
	tree->parent = right_child;

	return (new_root);
}
