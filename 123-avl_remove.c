#include "binary_trees.h"

void t_baf(avl_t **tree);
int next_tree(bst_t *node);
int ctrl_z(bst_t *root);
bst_t *deletes(bst_t *root, int value);

/**
 * avl_remove - removes a node from a AVL tree
 * @root:  pointer to node
 * @value: tree  val to remove
 *
 * Return: pointer new root node
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *undo = (avl_t *) deletes((bst_t *) root, value);

	if (undo == NULL)
		return (NULL);
	t_baf(&undo);
	return (undo);
}

/**
 * t_baf- Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */

void t_baf(avl_t **tree)
{
	int balance;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	t_baf(&(*tree)->left);
	t_baf(&(*tree)->right);
	balance = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * next_tree - return the sucessor of the tree
 * @node: node to check
 * Return: sucessor of the tree
 */

int next_tree(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = next_tree(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 *ctrl_z - deletes a nodes
 *@root: root of the node to remove
 *
 *Return: 0 if it has no sucessor
 */

int ctrl_z(bst_t *root)
{
	int update = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		update = next_tree(root->right);
		root->n = update;
		return (update);
	}
}
/**
 * deletes - removes node from a bst tree
 * @root: ...
 * @value: ...
 *
 * Return: updated tree
 */

bst_t *deletes(bst_t *root, int value)
{
	int t = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		deletes(root->left, value);
	else if (value > root->n)
		deletes(root->right, value);
	else if (value == root->n)
	{
		t = ctrl_z(root);
		if (t != 0)
			deletes(root->right, t);
	}
	else
		return (NULL);
	return (root);
}
