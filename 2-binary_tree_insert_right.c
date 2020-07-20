#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node to the right
* @parent: parent node pointer
* @value: value to put in node
* Return: pointer to new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
	{
		free(new);
		return (NULL);
	}
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;
	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
		parent->right = new;
	}
	else
	{
		parent->right = new;
	}
	return (new);
}
