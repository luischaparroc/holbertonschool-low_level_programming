#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}

/**
 * check_parent - checks if node has a lower/higher than its grand parent
 *
 * @tree: actual node
 * Return: 1 if actual node has an appropiartely value, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	const binary_tree_t *prnt;
	const binary_tree_t *grand_prnt;

	if (tree == NULL || tree->parent == NULL || tree->parent->parent == NULL)
		return (1);

	prnt = tree->parent;
	grand_prnt = prnt->parent;

	while (prnt && grand_prnt)
	{
		if (prnt->n < grand_prnt->n && tree->n >= grand_prnt->n)
			return (0);

		if (prnt->n > grand_prnt->n && tree->n <= grand_prnt->n)
			return (0);

		prnt = prnt->parent;
		grand_prnt = prnt->parent;
	}

	return (1);
}

/**
 * check_is_bst - checks if binary tree is a BST
 *
 * @tree: tree root
 * Return: 1 if tree is a BST, 0 otherwise
 */
int check_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!check_parent(tree->left) || !check_parent(tree->right))
		return (0);

	return (check_is_bst(tree->left) && check_is_bst(tree->right));
}

/**
 * binary_tree_is_bst - calls to check_is_bst to check if tree is BST
 *
 * @tree: tree root
 * Return: 1 if tree is a BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_is_bst(tree));
}
