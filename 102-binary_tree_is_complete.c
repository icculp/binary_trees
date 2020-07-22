#include "binary_trees.h"

/**
* binary_tree_size - measure size of tree
* @tree: tree is actually the node pointer
* Return: height
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 0, left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	size = left + right + 1;
	if (tree->left == NULL && tree->right == NULL)
		return (size);
	return (size);
}

/**
* check - recurssive function to check is complete
* @tree: tree
* @index: index
* @nodes: size
* Return: height
*/

bool check(binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (true);
	if (index >= nodes)
		return (false);
	return (check(tree->left, 2 * index + 1, nodes) &&
		check(tree->right, 2 * index + 2, nodes));
}

/**
* binary_tree_is_complete - make sure binary tree is complete
* @tree: tree pointer
* Return: yes or no
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes, c;

	if (tree == NULL)
		return (0);
	nodes = binary_tree_size(tree);
	c = check((binary_tree_t *)tree, 0, nodes);
	if (c)
		return (1);
	return (0);
}
