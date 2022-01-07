#include "../includes/libft.h"

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	FILE *input = NULL;
	char word[BUFF];

	if (argc != 2)
		ft_error(ERR_ARG);

	input = openread(argv, input);
	if (fscanf(input, "%s", word) > 0)
	{
		wordFormat(word);
		root = insert(root, hash(word), word);
	}
	while (fscanf(input, "%s", word) > 0)
	{
		wordFormat(word);
		insert(root, hash(word), word);
	}
	printf("%-11s %-10s %s\n", "hash", "key", "value");
	inorder(root);
	return 0;
}
