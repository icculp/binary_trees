#include "binary_trees.h"

/**
* bst_search - search bst for value
* @tree: tree to search
* @value: value to search for
* Return: pointer to node with value or NULL
*/

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));
	return (NULL);
}
