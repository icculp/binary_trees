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
* avl_insert - inserts into avl without losing balance
* @tree: tree to insert into
* @value: value to insert
* Return: pointer to new node or NULL
*/

avl_t *avli(avl_t *tree, int value)
{
	int bal = 0;

	printf("65\n");
	printf("66 tree: %d\n", tree->n);
	if (value < tree->n)
	{
		printf("68\n");
		if (tree->left)
			tree = avli(tree->left, value);
		else
			tree->left = binary_tree_node(tree, value);
	}
	else if (value > tree->n)
	{
		printf("73\n");
		if (tree->right)
			tree = avli(tree->right, value);
		else
		{
			printf("82\n");
			tree->right = binary_tree_node(tree, value);
		}

		printf("75");
	}
	else
	{
		printf("78\n");
		return (tree);
	}
	printf("72\n");
	if (tree)
	{

		bal = binary_tree_balance(tree);
	}

	printf("Balance: %d\n", bal);
	printf("1\n");
	if (bal > 0 && value > tree->left->n)
	{
		printf("first\n");
		return binary_tree_rotate_right(tree);
	}
	printf("wtf\n");
	if (bal < 0 && value < tree->right->n)
	{
		printf("second\n");
		return binary_tree_rotate_left(tree);
	}
	printf("2");
	if (bal > 0 && value > tree->left->n)
	{
		printf("third\n");
		tree->left = binary_tree_rotate_left(tree->left);
		return binary_tree_rotate_right(tree);
	}
	if (bal < 0 && value > tree->right->n)
	{
		printf("fourth\n");
		tree->right = binary_tree_rotate_right(tree->right);
		return binary_tree_rotate_left(tree);
	}
	printf("3");
	return (tree);
}


/**
* avl_insert - inserts into avl without losing balance
* @tree: tree to insert into
* @value: value to insert
* Return: pointer to new node or NULL
*/

avl_t *avl_insert(avl_t **tree, int value)
{


	printf("start");
	if (tree == NULL)
	{
		printf("d");
		return (NULL);
	}
	if (*tree == NULL)
	{
		printf("e");
		*tree = binary_tree_node(NULL, value);
		printf("ef");
		return ((avl_t *)*tree);
	}
	printf("1f");
	printf("why you ignore me?\n");
	printf("130 tree: %d\n", (*tree)->n);
	avli((avl_t *)*tree, value);
/**	bal = binary_tree_balance(*tree);
	if (bal > 0 && value < (*tree)->left->n)
	{
		printf("first\n");
		return binary_tree_rotate_right(*tree);
	}
	if (bal < 0 && value > (*tree)->right->n)
	{
		printf("second\n");
		return binary_tree_rotate_left(*tree);
	}
	printf("2");
	if (bal > 0 && value > (*tree)->left->n)
	{
		printf("third\n");
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return binary_tree_rotate_right(*tree);
	}
	if (bal < 0 && value < (*tree)->right->n)
	{
		printf("fourth\n");
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return binary_tree_rotate_left(*tree);
	}*/

	return (*tree);
}
