#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts a node to the left
* @parent: parent node pointer
* @value: value to put in node
* Return: pointer to new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
		parent->left = new;
	}
	else
	{
		parent->left = new;
	}
	return (new);
}
