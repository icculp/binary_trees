#include "binary_trees.h"

/**
* bst_insert - insert for bst
* @tree: double pointer to tree
* @value: value to insert
* Return: pointer to new node
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp;

	if (!tree)
		return (NULL);
	temp = *tree, new = binary_tree_node(NULL, value);
	if (!*tree)
	{
		(*tree) = new;
		return (*tree);
	}
	while (temp)
	{
		if (temp->n == value)
		{
			free(new);
			return (NULL);
		}
		if (value > temp->n)
		{
			if (temp->right)
				temp = temp->right;
			else
			{
				temp->right = new, new->parent = temp;
				return (new);
			}
		}
		else
		{
			if (temp->left != NULL)
				temp = temp->left;
			else
			{
					temp->left = new, new->parent = temp;
					return (new);
			}
		}
	}
	free(new);
	return ((*tree));
}

/**
* avli - avl insert recursion
* @tree: tree to insert into
* @value: value to insert
* Return: pointer to new node or NULL
*/

avl_t *avli(avl_t *tree, int value)
{
	int bal = 0;

	if (value < tree->n)
	{
		if (tree->left)
			tree = avli(tree->left, value);
		else
			tree->left = binary_tree_node(tree, value), tree = tree->left;
	}
	else if (value > tree->n)
	{
		if (tree->right)
			tree = avli(tree->right, value);
		else
			tree->right = binary_tree_node(tree, value), tree = tree->right;
	}
	else
		return (tree);
	if (tree->parent && tree->parent->parent)
		bal = binary_tree_balance(tree->parent->parent);
	else if (tree->parent)
		bal = binary_tree_balance(tree->parent);
	else
		bal = binary_tree_balance(tree);
	if (bal > 1 && tree->parent && tree->parent->left &&
		value < tree->parent->left->n)
		return (binary_tree_rotate_right(tree));
	if (bal < -1 && tree->parent && tree->parent->right &&
		value > tree->parent->right->n)
		return (binary_tree_rotate_left(tree));
	if (bal > 1 && tree->parent && tree->parent->parent &&
		value == tree->parent->right->n)
	{/** && tree->parent->n == tree->parent->parent->left->n)*/
		tree = binary_tree_rotate_left(tree->parent);
		return (binary_tree_rotate_right(tree->parent));
	}
	if (bal < -1 && tree->parent && tree->parent->parent &&
		value == tree->parent->right->n)
		binary_tree_rotate_left(tree->parent->parent);
	return (tree);
} /**return binary_tree_rotate_left(tree);*/
/** && value < tree->parent->right->n)*/

/**
* avl_insert - inserts into avl without losing balance
* @tree: tree to insert into
* @value: value to insert
* Return: pointer to new node or NULL
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return ((avl_t *)*tree);
	}
	return (avli((avl_t *)*tree, value));
}
