#include "binary_trees.h"
#include "9-binary_tree_height.c"
int bti_avl(const binary_tree_t *tree, int mini, int maxi);

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bti_avl(tree, INT_MIN, INT_MAX));
}

/**
 * bti_avl - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @mini: minimum value
 * @maxi: maximum value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */
int bti_avl(const binary_tree_t *tree, int mini, int maxi)
{
	int left_path, right_path;

	if (!tree)
		return (1);
	if (tree->n < mini || tree->n > maxi)
		return (0);

	left_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(left_path - right_path) > 1)
		return (0);

	return (bti_avl(tree->left, mini, tree->n - 1) &&
		bti_avl(tree->right, tree->n + 1, maxi));
}
