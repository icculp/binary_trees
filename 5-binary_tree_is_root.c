#include "binary_trees.h"

/**
* binary_tree_is_root - checks if a node is root (end node)
* @node: node pointer
* Return: 1 if leaf, 0 if not
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	else
	{
		if (node->parent == NULL)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
