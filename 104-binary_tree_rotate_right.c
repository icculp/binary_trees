#include "binary_trees.h"

/**
* binary_tree_rotate_right - rotate right
* @tree: tree is actually the node pointer
* Return: pointer to new root
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p, *pr;

	if (tree == NULL || !tree->left)
		return (NULL);
	p = tree->left;
	p->parent = tree->parent;
	pr = p->right;
	p->right = tree;
	tree->parent = p;
	tree->left = pr;
	if (pr)
		pr->parent = p;
	return (p);
}
