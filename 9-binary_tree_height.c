#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL, else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lefty, righty = 0;

	if (!tree)
		return (0);

	lefty = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	righty = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (lefty > righty ? lefty : righty);
}
