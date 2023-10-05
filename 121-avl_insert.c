#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: A double pointer to the root node of the AVL tree to insert into
 * @value: The value to insert into the AVL tree
 *
 * Return: A pointer to the inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	inserts_recursive(tree, *tree, &new, value);
	return (new);
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL else return height
 */
size_t height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree != NULL)
	{

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0 ,otherwise return balance factor
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * inserts_recursive - inserts a value into an AVL tree recursively
 * @tree: double pointer to the root node of the AVL tree to insert into
 * @parent: parent node of the current working node
 * @new: double pointer to store the new node
 * @value: value to insert into the AVL tree
 *
 * Return: pointer to the new root after insertion, or NULL on failure
 */

avl_t *inserts_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = inserts_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = inserts_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	factor = balance(*tree);
	if (factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
