#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root:  ...
 *
 * Return: the value stored in the root node or 0 on failure
 **/

int heap_extract(heap_t **root)
{
	int num;
	heap_t *load, *node;

	if (!root || !*root)
		return (0);
	load = *root;
	num = load->n;
	if (!load->left && !load->right)
	{
		*root = NULL;
		free(load);
		return (num);
	}

	initializer(load, &node, checks_height(load));

	load->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(load);
	*root = load;
	return (num);
}

/**
 * checks_height - checks for the height of a binary tree
 * @tree: pointer value
 *
 * Return: tree height or 0 if tree is NULL
 */

size_t checks_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + checks_height(tree->left);

	if (tree->right)
		height_right = 1 + checks_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}

/**
 * tree_height - measures the sum of heights of a binary tree
 * @tree: ...
 *
 * Return: ...
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_height(tree->right);

	return (height_left + height_right);
}

/**
 * initializer - traverses through a binary tree using pre-order traversal
 * @tree: ptr to the root node of the tree to traverse
 * @node: node to traverse
 * @height: tree height
 *
 */

void initializer(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	initializer(tree->left, node, height);
	initializer(tree->right, node, height);
}

/**
 * heapify - heapifies a Max Binary Heap
 * @root: is a ptr
 */

void heapify(heap_t *root)
{
	int num;
	heap_t *tmp, *temp;

	if (!root)
		return;

	tmp = root;

	while (1)
	{
		if (!tmp->left)
			break;
		if (!tmp->right)
			temp = tmp->left;
		else
		{
			if (tmp->left->n > tmp->right->n)
				temp = tmp->left;
			else
				temp = tmp->right;
		}
		if (tmp->n > temp->n)
			break;
		num = tmp->n;
		tmp->n = temp->n;
		temp->n = num;
		tmp = temp;
	}
}
