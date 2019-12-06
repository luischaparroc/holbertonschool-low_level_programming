#include "binary_trees.h"

/**
 * check_balance_avl - checks the balance of each node
 *
 * @node: pointer to the node
 * @value: input value
 * Return: no return
 */
void check_balance_avl(avl_t **node, int value)
{
	int balance;

	balance = binary_tree_balance(*node);

	if (balance > 1 && value > (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value < (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (balance > 1 && value < (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value > (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * inorder_sucessor - determines the next/previous node of the removed node
 *
 * @tree: pointer to the node
 * @mode: 1 for inorder sucessor, 2 for inorder precessor
 * Return: pointer to the next/previous node
 */
avl_t *inorder_sucessor(avl_t *tree, int mode)
{
	avl_t *node;

	if (mode == 1)
	{
		if (tree->left == NULL)
		{
			if (tree == tree->parent->left)
				tree->parent->left = NULL;
			else
				tree->parent->right = NULL;

			return (tree);
		}

		node = inorder_sucessor(tree->left, 1);
	}
	else
	{
		if (tree->right == NULL)
		{
			if (tree == tree->parent->right)
				tree->parent->right = NULL;
			else
				tree->parent->left = NULL;

			return (tree);
		}

		node = inorder_sucessor(tree->right, 2);
	}

	return (node);
}

/**
 * change_node - changes the removed node by the next/previous node
 *
 * @arg_tree: pointer to the removed node
 * @arg_node: poitner to the next/previous node
 * Return: no return
 */
void change_node(avl_t **arg_tree, avl_t **arg_node)
{
	avl_t *put_node, *tree;

	put_node = *arg_node;
	tree = *arg_tree;

	if (tree->left && tree->left != put_node)
	{
		if (put_node->left)
		{
			put_node->parent->right = put_node->left;
			put_node->left->parent = put_node->parent;
		}

		put_node->left = tree->left;
		tree->left->parent = put_node;
	}
	if (tree->right && tree->right != put_node)
	{
		if (put_node->right)
		{
			put_node->parent->left = put_node->right;
			put_node->right->parent = put_node->parent;
		}

		put_node->right = tree->right;
		tree->right->parent = put_node;
	}

	put_node->parent = tree->parent;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = put_node;
		else
			tree->parent->right = put_node;
	}

	*arg_tree = tree;
	*arg_node = put_node;
}


/**
 * avl_search_remove - searches to remove a node in an AVL tree
 *
 * @tree: tree root
 * @value: node value
 * Return: pointer the removed node
 */
avl_t *avl_search_remove(avl_t **tree, int value)
{
	avl_t *put_node;

	if (tree && *tree && value < (*tree)->n)
	{
		put_node = avl_search_remove(&((*tree)->left), value);
		check_balance_avl(tree, value);
		return (put_node);
	}
	if (tree && *tree && value > (*tree)->n)
	{
		put_node = avl_search_remove(&((*tree)->right), value);
		check_balance_avl(tree, value);
		return (put_node);
	}
	if (tree && *tree)
	{
		if ((*tree)->left || (*tree)->right)
		{
			if ((*tree)->right)
				put_node = inorder_sucessor((*tree)->right, 1);
			else
				put_node = inorder_sucessor((*tree)->left, 2);
			change_node(tree, &put_node);
			free(*tree);
			*tree = put_node;
		}
		else
		{
			put_node = *tree;
			if ((*tree)->parent)
			{
				if ((*tree)->parent->left == (*tree))
					(*tree)->parent->left = NULL;
				else
					(*tree)->parent->right = NULL;
			}
			free(put_node), *tree = NULL;
		}
	}
	return (*tree);
}


/**
 * avl_remove - removes a node in an AVL tree
 *
 * @root: tree root
 * @value: node value
 * Return: pointer to the new root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	avl_search_remove(&root, value);

	return (root);
}
