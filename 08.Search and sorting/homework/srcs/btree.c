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
	inorder(root->right);
}

// int main()
// {
// 	struct node *root = NULL;
// 	root = insert(root, hash("hello"), "hello");
// 	insert(root, hash("hello1"), "hello1");
// 	insert(root, hash("hello2"), "hello2");
// 	insert(root, hash("hello3"), "hello3");
// 	insert(root, hash("hello6"), "hello6");
// 	insert(root, hash("hello6"), "hello6");
// 	insert(root, hash("hello6"), "hello6");
// 	insert(root, hash("hello7"), "hello7");
// 	insert(root, hash("hello8"), "hello8");
// 	inorder(root);
// 	printf("\n");
// }
