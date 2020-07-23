#include "binary_trees.h"

/**
* binary_tree_is_full - check if tree is full
* @tree: tree pointer
* Return: 1 or 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
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
* binary_tree_is_perfect - function
* @tree: tree to check
* Description: check if a binary tree is balanced and full
* Return: 1 if perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int counterL = 0, counterR = 0;

	if (tree == NULL)
		return (0);


	if (tree->left != NULL)
		counterL = binary_tree_height(tree->left);

	if (tree->right != NULL)
		counterR = binary_tree_height(tree->right);

	if (counterL - counterR == 0 && binary_tree_is_full(tree))
		return (1);
	else
		return (0);
}
