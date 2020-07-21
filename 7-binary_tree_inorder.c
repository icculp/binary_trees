#include "binary_trees.h"

/**
* binary_tree_inorder - print a binary tree using inorder traversal
* @tree: tree pointer
* @func: function pointer to use on value of node
* Return: 1 if leaf, 0 if not
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || (*func) == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	(*func)(tree->n);
	binary_tree_inorder(tree->right, func);
}
