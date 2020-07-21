#include "binary_trees.h"

/**
* binary_tree_depth - measure height of node
* @tree: tree is actually the node pointer
* Return: height
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *temp = tree;
	int depth = 0;

	if (tree == NULL)
		return (0);
	while (temp->parent != NULL)
	{
		temp = temp->parent;
		depth++;
	}
	return (depth);
}
