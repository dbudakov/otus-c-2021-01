/*https://evileg.com/ru/post/491/*/

#include "../includes/libft.h"

struct node *createNode(int index, char *key)
{
	struct node *newNode = malloc(sizeof(struct node));
	if (newNode == NULL)
		ft_error(errno);
	newNode->index = index;
	newNode->key = ft_strdup(key);
	newNode->value = 1;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

struct node *insert(struct node *root, int index, char *key)
{
	if (root == NULL)
		return createNode(index, key);

	if (index == root->index)
		root->value++;
	else if (index < root->index)
		root->left = insert(root->left, index, key);
	else if (index > root->index)
		root->right = insert(root->right, index, key);

	return root;
}

void inorder(struct node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%-10d, %-10s: %d\n", root->index, root->key, root->value);
	free(root->key);
	free(root);
	inorder(root->right);
}
