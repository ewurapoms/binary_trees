#include "binary_trees.h"

int pow_recursion(int a, int b);
/**
 *pow_recursion - returns the value of 'a' raised to the power of 'b'
 *@a: the value to exponentiate
 *@b: the power to raise a to
 *Return: a to the power of b, or -1 if b is negative
 */

int pow_recursion(int a, int b)
{
	if (b < 0)
		return (-1);
	if (b == 0)
		return (1);
	else
		return (a * pow_recursion(a, b - 1));

}

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
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to root node of tree to measure
 *
 * Return: size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect else 0 or NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t nodes, pow, height = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	pow = (size_t)pow_recursion(2, height + 1);
	return (pow - 1 == nodes);
}
