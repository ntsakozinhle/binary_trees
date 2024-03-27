#include "binary_trees.h"
#include <stdio.h>


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
 * dfs_levelorder - Helper function to perform depth-limited DFS for level-
 * order traversal
 * @node: Current node being visited
 * @func: A pointer to a function to call for each node
 * @depth_limit: Depth limit DFS
 *
 * Return: 1 if at least one node was visited at the current depth
 */
int dfs_levelorder(const binary_tree_t *tree, void (*func)(int), size_t depth_limit)
{
	if (tree == NULL || func == NULL)
		return (0);
	
	if (depth_limit == 0)
		return (1);

	if (depth_limit == 1)
	{
		func(tree->n);
		return (1);
	}

	return (dfs_levelorder(tree->left, func, depth_limit - 1) && dfs_levelorder(tree->right, func, depth_limit - 1));
}


/**
 * binary_tree_levelorder - Performs level-order traversal on binary tree
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t depth;
	size_t i;
	
	if (tree == NULL || func == NULL)
		return;

	depth = binary_tree_height(tree) + 1;

	for (i = 1; i<= depth; i++)
		dfs_levelorder(tree, func, i);
}
