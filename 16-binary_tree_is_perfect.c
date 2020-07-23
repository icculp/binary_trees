#include "binary_trees.h"

/**
* bdepth - measure depth of left branch
* @tree: tree pointer
* Return: height
*/

int bdepth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
* perfect_recursion - recursive algorithm for checking if btree is perfect
* @tree: tree pointer
* @d: depth of left branch
* @level: level of tree
* Return: 1 or 0
*/

int perfect_recursion(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (true);
	if (tree->left == NULL && tree->right == NULL)
	{
		return (d == (level + 1));
	}
	if (tree->left == NULL || tree->right == NULL)
		return (false);
	return (perfect_recursion(tree->left, d, level + 1) &&
		perfect_recursion(tree->right, d, level + 1));
}

/**
* binary_tree_is_perfect - check if tree is perfect
* @tree: tree pointer
* Return: 1 or 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);
	d = bdepth(tree);
	if (perfect_recursion(tree, d, 0))
		return (1);
	return (0);
}
