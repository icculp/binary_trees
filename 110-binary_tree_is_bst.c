#include "binary_trees.h"

/**
* bstr - is bst recursive helper
* @tree: tree is actually the node pointer
* @min: int min but narrows by value
* @max: int max but narrows by value
* Return: yes or no
*/

int bstr(binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bstr(tree->left, min, tree->n - 1) &&
		bstr(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_bst - checks if bt is bst
* @tree: tree is actually the node pointer
* Return: yes or no
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bstr((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
