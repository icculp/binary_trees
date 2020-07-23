#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
* @parent: parent node pointer
* @value: value to put in node
* Return: pointer to new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	printf("00000");
	if (new == NULL)
		return (NULL);
	printf("after");
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->n = value;
	return (new);
}
