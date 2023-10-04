#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to root node of tree to count
 *
 * Return: 0 if tree is NULL number of nodes counted
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t btn = 0;

	if (tree)
	{
		btn += (tree->left || tree->right) ? 1 : 0;
		btn += binary_tree_nodes(tree->left);
		btn += binary_tree_nodes(tree->right);
	}
	return (btn);
}
