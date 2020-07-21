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
		return (left + 1);
	}
	else
	{
		return (right + 1);
	}
}

/**
* binary_tree_balance - measure balance of tree
* @tree: tree is actually the node pointer
* Return: balance
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0, left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

/**	printf("l %d r %d\n", left, right);*/
	balance = left - right;
	return (balance);
}
