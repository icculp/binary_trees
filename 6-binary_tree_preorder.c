#include "binary_trees.h"

/**
* binary_tree_preorder - checks if a node is root (end node)
* @tree: tree pointer
* @func: function pointer to use on value of node
* Return: 1 if leaf, 0 if not
*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || (*func) == NULL)
		return;
	(*func)(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
