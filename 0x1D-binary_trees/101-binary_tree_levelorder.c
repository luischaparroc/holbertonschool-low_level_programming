#include "binary_trees.h"

/**
 * recursive_height - measures the height of a binary tree
 *
 * @tree: tree root
 * Return: height
 */
size_t recursive_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = recursive_height(tree->left);
	right = recursive_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * print_level - prints nodes at the same level
 *
 * @tree: tree root
 * @level: level node
 * @func: pointer to a function
 * Return: no return
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints data in level-order traversal
 *
 * @tree: tree root
 * @func: pointer to a function
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	height = recursive_height(tree);

	for (i = 1; i <= height; i++)
		print_level(tree, i, func);
}
