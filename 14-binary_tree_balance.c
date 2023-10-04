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

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, else the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lefty, righty;

	if (!tree)
		return (0);

	lefty = tree->left ? (int)binary_tree_height(tree->left) : -1;
	righty = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (lefty - righty);
}
