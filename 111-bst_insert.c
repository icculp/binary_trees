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
	temp = *tree;
	new = binary_tree_node(NULL, value);
	if (!*tree)
	{
		(*tree) = new;
		return (*tree);
	}
	while (temp)
	{
		if (temp->n == value)
			return (NULL);
		if (value > temp->n)
		{
			if (temp->right)
				temp = temp->right;
			else
			{
				temp->right = new;
				new->parent = temp;
				return (new);
			}
		}
		else
		{
			if (temp->left != NULL)
				temp = temp->left;
			else
			{
					temp->left = new;
					new->parent = temp;
					return (new);
			}
		}
	}
	return ((*tree));
}

/**
 * recursion_hurts_doing_iterative - fuck this
*/

void recursion_hurts_doing_iterative(void)
{
/**
 * recursion_hurts_doing_iterative - fuck this
 * recursion hurting my brain, fuckit, gonna do iterative
 *  if (value < (*tree)->n)
 *   {
 *	(*tree)->left = bst_insert(&(*tree)->left, value), printf("35\n");
 *		return (*tree)->left;
 *	}
 *	else if (value > (*tree)->n)
 *	{
 *		(*tree)->right = bst_insert(&(*tree)->right, value), printf("37\n");
*			return (*tree)->right;
*	}
*	else if (value == (*tree)->n)
*	{
*		printf("43\n");
*		return (NULL);
*	}
*/
}
