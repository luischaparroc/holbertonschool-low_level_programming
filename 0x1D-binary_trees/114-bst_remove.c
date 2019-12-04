#include "binary_trees.h"

/**
 * r_case - removes a node from a Binary Search Tree for node->right case
 * @root: tree root
 * @node: node to delete
 * Return: pointer the tree root
 */
bst_t *r_case(bst_t *node, bst_t *root)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (node->left)
		node->left->parent = node->right;
	if (root == node)
		root = node->right;
	free(node);
	return (root);
}

/**
 * r_l_case - removes a node from a Binary Search Tree for node->right->l case
 * @root: tree root
 * @node: node to delete
 * Return: pointer the tree root
 */
bst_t *r_l_case(bst_t *node, bst_t *root)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (root == node)
		root = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);
	return (root);
}

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
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: tree root
 * @value: node value
 * Return: pointer the found node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree && value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: tree root
 * @value: node value
 * Return: pointer the tree root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if (node != NULL)
	{
		if (binary_tree_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = r_l_case(node, root);
		else if (node->right)
			root = r_case(node, root);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (root == node)
				root = node->left;
			free(node);
		}
	}
	return (root);
}
