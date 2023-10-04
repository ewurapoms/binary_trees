#include "binary_trees.h"
#include "9-binary_tree_height.c"

void _btlev(const binary_tree_t *tree, void (*func)(int), size_t level);

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		_btlev(tree, func, level);
}

/**
 * _btlev - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void _btlev(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		_btlev(tree->left, func, level - 1);
		_btlev(tree->right, func, level - 1);
	}
}
