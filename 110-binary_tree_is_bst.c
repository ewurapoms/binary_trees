#include "binary_trees.h"

int _btib(const binary_tree_t *tree, int mini, int maxi);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_btib(tree, INT_MIN, INT_MAX));
}

/**
 * _btib - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @mini: lower bound for values in the tree
 * @maxi: highest bound for values in the tree
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int _btib(const binary_tree_t *tree, int mini, int maxi)
{
	if (!tree)
		return (1);

	if (tree->n < mini || tree->n > maxi)
		return (0);

	return (_btib(tree->left, mini, tree->n - 1) &&
		_btib(tree->right, tree->n + 1, maxi));
}
