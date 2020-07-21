#include "binary_trees.h"

/**
* binary_tree_size - measure size of tree
* @tree: tree is actually the node pointer
* Return: height
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 0, left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	size = left + right + 1;
	if (tree->left == NULL && tree->right == NULL)
		return (size);
	return (size);
}
