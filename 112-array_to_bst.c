#include "binary_trees.h"

/**
* array_to_bst - convert array to bst
* @array: Array to convert
* @size: size of array
* Return: pointer to root of bst or NULL on fail
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	int i;

	if (!array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
