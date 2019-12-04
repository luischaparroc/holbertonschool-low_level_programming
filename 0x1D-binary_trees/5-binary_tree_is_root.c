#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int root = 0;

	if (node && !(node->parent))
		root = 1;

	return (root);
}
