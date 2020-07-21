#include "binary_trees.h"

/**
* binary_tree_nodes - measure number of nodes with at least 1 child
* @tree: tree is actually the node pointer
* Return: height
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int size = 0, left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);

	size = left + right;
	if (tree->left != NULL || tree->right != NULL)
		return (size + 1);
	return (size);
}
