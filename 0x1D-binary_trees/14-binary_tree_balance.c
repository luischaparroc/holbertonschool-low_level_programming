#include "binary_trees.h"

/**
 * recursive_balance - measures the balance factor of a binary tree
 *
 * @tree: tree root
 * Return: balance factor
 */
int recursive_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (recursive_balance(tree->left) - recursive_balance(tree->right));
}

/**
 * binary_tree_balance - calls recursive_balance to return the balance
 * of a binary tree
 *
 * @tree: tree root
 * Return: balance factor of the tree or 0 if tree is NULL;
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recursive_balance(tree));
}
