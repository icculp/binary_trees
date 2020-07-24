#include "binary_trees.h"

/**
* binary_tree_rotate_left - rotate left
* @tree: tree is actually the node pointer
* Return: pointer to new root
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *p, *pl;

	if (tree == NULL)
		return (0);
	if (tree->parent)
	{
		if (tree->parent->right && tree->parent->right->n == tree->n)
			tree->parent->right = tree->right;
		else
			tree->parent->left = tree->right;
	}
	p = tree->right;
	p->parent = tree->parent;
	pl = p->left;
	p->left = tree;
	tree->parent = p;
	tree->right = pl;
	if (pl)
		pl->parent = p;
	return (p);
}
