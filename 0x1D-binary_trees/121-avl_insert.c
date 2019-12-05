#include "binary_trees.h"

/**
 * avl_in - checks if node is inserted
 *
 * @tree: tree root
 * @value: node value
 * Return: pointer to the new node
 */
avl_t *avl_in(avl_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (avl_in(&((*tree)->left), value));
		}
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			return (avl_in(&((*tree)->right), value));
		}
	}

	return (NULL);
}

/**
 * pre_rotation - pre_rotates a tree
 *
 * @arg_node: pointer to the node
 * Return: no return
 */
void pre_rotation(avl_t **arg_node)
{
	avl_t *node;

	node = *arg_node;

	if (node->left && node->left->left == NULL && node->left->right)
	{
		tree = node->left;
		new_root = tree->right;

		tree->right = NULL;

		new_root->left = tree;
		new_root->parent = tree->parent;
		tree->parent = new_root;

		node->left = new_root;
	}

	if (node->right && node->right->right == NULL && node->right->left)
	{
		tree = node->right;
		new_root = tree->left;

		tree->left = NULL;

		new_root->right = tree;
		new_root->parent = tree->parent;
		tree->parent = new_root;

		node->right = new_root;
	}

	*arg_node = node;
}

/**
 * check_balance - checks the balance of each node
 *
 * @node: pointer to the node
 * @tree: pointer to the tree
 * Return: no return
 */
void check_balance(avl_t **node, avl_t **tree)
{
	avl_t *pointer_node;
	int balance;

	if (*node == NULL)
		return;

	pointer_node = *node;
	balance = binary_tree_balance(*node);

	if (balance == 2)
	{
		pre_rotation(&pointer_node);
		if (pointer_node->parent == NULL)
			*tree = binary_tree_rotate_right(pointer_node);
		else
		{
			if (pointer_node == pointer_node->parent->left)
				pointer_node->parent->left = binary_tree_rotate_right(pointer_node);
			else
				pointer_node->parent->right = binary_tree_rotate_right(pointer_node);
		}
	}
	else if (balance == -2)
	{
		pre_rotation(&pointer_node);
		if (pointer_node->parent == NULL)
			*tree = binary_tree_rotate_left(pointer_node);
		else
		{
			if (pointer_node == pointer_node->parent->left)
				pointer_node->parent->left = binary_tree_rotate_left(pointer_node);
			else
				pointer_node->parent->right = binary_tree_rotate_left(pointer_node);
		}
	}
	else
	{
		check_balance(&((*node)->parent), tree);
	}
}


/**
 * avl_insert - inserts a value in a AVL Tree
 *
 * @tree: tree root
 * @value: node value
 * Return: pointer to the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = avl_in(tree, value);

	if (node)
		check_balance(&node, tree);

	return (node);
}
