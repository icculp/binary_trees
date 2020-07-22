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

/**
* binary_trees_ancestor - return lowest common ancestor
* @first: first node pointer
* @second: second node pointer
* Return: pointer to lca
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *ft = first, *st = second;
	int fd, sd;

	fd = binary_tree_depth(ft);
	sd = binary_tree_depth(st);

	while (fd > sd)
	{
		ft = ft->parent;
		fd = binary_tree_depth(ft);
	}
	while (sd > fd)
	{
		st = st->parent;
		sd = binary_tree_depth(st);
	}
	while (sd == fd && st != ft)
	{
		st = st->parent;
		ft = ft->parent;
		if (!st || !ft)
			return (NULL);
	}
	return ((binary_tree_t *)ft);
}
