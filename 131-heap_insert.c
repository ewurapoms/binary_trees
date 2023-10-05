#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: ptr
 * @value: ...
 *
 * Return: ptr to new node else NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int branch, temp;
	int size, leaf, sub, bud;
	heap_t *tree, *new, *stem;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (branch = 0, sub = 1; leaf >= sub; sub *= 2, branch++)
		leaf = leaf - sub;

	for (bud = 1 << (branch - 1); bud != 1; bud >>= 1)
		tree = leaf & bud ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = new) : (tree->left = new);

	stem = new;
	for (; stem->parent && (stem->n > stem->parent->n); stem = stem->parent)
	{
		temp = stem->n;
		stem->n = stem->parent->n;
		stem->parent->n = temp;
		new = new->parent;
	}

	return (new);
}
