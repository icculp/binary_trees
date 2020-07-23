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

/**
* successor - search for inorder successor
* @node: right node of deleted node to find successor of
* Return: inorder successor
*/

bst_t *successor(bst_t *node)
{
	bst_t *temp = node;

	printf("successor\n");
	while (temp && temp->left)
		temp = temp->left;
	return (temp);
}
/**
* bst_remove - remove value from bst
* @root: tree to search
* @value: value to remove
* Return: pointer to node with value or NULL
*/

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del = bst_search(root, value), *temp;

	if (!del)
		return (NULL);
	if (del->left == NULL || del->right == NULL)
	{
		if (!del->left)
			temp = del->right;
		else
			temp = del->left;
		temp->parent = del->parent;
		if (del->parent)
		{
			if (del->parent->right->n == del->n)
				del->parent->right = temp;
			else
				del->parent->left = temp;
		}
		free(del);
		return (root);
	}
	temp = successor(del->right);
	if (temp)
	{
		del->n = temp->n;
		if (temp->n != del->right->n)
			temp->parent->left = NULL;
		else
			del->right = NULL;
		free(temp);
	}
	else
		del->n = del->left->n, free(del->left), del->left = NULL;
	return (root);
}
