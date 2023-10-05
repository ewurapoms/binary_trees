#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i = 0;
	avl_t *root = NULL;

	for (; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
