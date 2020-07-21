#include "binary_trees.h"

/**
* binary_tree_height - measure height of binary tree
* @tree: tree pointer
* Return: height
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left > right)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (left);
		else
			return (left + 1);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (right);
		else
			return (right + 1);
	}
}
