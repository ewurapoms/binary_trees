#include "binary_trees.h"

/**
 * tree_size - returns the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree for height measuring
 *
 * Return: height or 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_size(tree->left);

	if (tree->right)
		height_right = 1 + tree_size(tree->right);

	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 *                       to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: array sorted in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int k, *t = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	t = malloc(sizeof(int) * (*size));

	if (!t)
		return (NULL);

	for (k = 0; heap; k++)
		t[k] = heap_extract(&heap);

	return (t);
}
