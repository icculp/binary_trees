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
		return (left + 1);
	}
	else
	{
		return (right + 1);
	}
}

/**
* avl - checks if valid avl recursively
* @tree: tree to search
* Return: yes or no
*/

bool avl(binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (true);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (abs(left - right) < 2 && avl(tree->left) && avl(tree->right))
		return (true);
	return (false);
}


/**
* binary_tree_is_avl - checks if valid avl
* @tree: tree to search
* Return: yes or no
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (avl((binary_tree_t *)tree) && binary_tree_is_bst(tree))
		return (1);
	return (0);
}
