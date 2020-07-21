#include "binary_trees.h"

/**
* binary_tree_leaves - measure number of leaves
* @tree: tree is actually the node pointer
* Return: height
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int size = 0, left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	size = left + right;
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (size);
}
