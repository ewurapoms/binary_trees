#include "binary_trees.h"

/**
 * binary_tree_sibling -locates the sibling of a node
 * @node: pointer to the node
 *
 * Return: pointer to the sibling node
 *         NULL if node/Parent is NULL or has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
