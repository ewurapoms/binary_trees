#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *centre, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	centre = tree->left;
	temp = centre->right;
	centre->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = centre;
	centre->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = centre;
		else
			temp->right = centre;
	}

	return (centre);
}
