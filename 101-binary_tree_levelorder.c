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

/**
 * printGivenLevel - print helper
 * @tree: tree
 * @level: level
 * @func: function pointer to use in printing
*/

void printGivenLevel(binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		(*func)(tree->n);
	else if (level > 1)
	{
		printGivenLevel(tree->left, level - 1, (*func));
		printGivenLevel(tree->right, level - 1, (*func));
	}
}


/**
* binary_tree_levelorder - traverse in level order
* @tree: tree is actually the node pointer
* @func: function pointer to use in printing
* Return: height
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = binary_tree_height(tree), i;

	if (tree == NULL || (*func) == NULL)
		return;
	for (i = 1; i <= h + 1; i++)
	{
		printGivenLevel((binary_tree_t *)tree, i, (*func));
	}
}
