#include "binary_trees.h"

/**
 * bst_remove - Removes node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (undo_r(root, root, value));
}

/**
 * nonpredecessor - Returns the inorder sucessor of a binary search tree.
 * @root: pointer to the root node of the BST to search
 *
 * Return: tree's min value
 */

bst_t *nonpredecessor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * delete - deletes a node from a BST
 * @root: the pointer to the root node of the BST
 * @node: the pointer to the node to delete from the BST
 *
 * Return: pointer to the new root node once deletion is done
 */

bst_t *delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *child = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	child = nonpredecessor(node->right);
	node->n = child->n;

	return (delete(root, child));
}

/**
 * undo_r -  recursively removes a node
 * @root: pointer to the root node of the BST to remove a node from
 * @node: pointer to the present node in the BST
 * @value: the value to remove from the BST
 *
 * Return: pointer to the root node after deletion
 */
bst_t *undo_r(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete(root, node));
		if (node->n > value)
			return (undo_r(root, node->left, value));
		return (undo_r(root, node->right, value));
	}
	return (NULL);
}
