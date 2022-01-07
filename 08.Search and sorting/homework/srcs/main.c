#include "../includes/libft.h"

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	FILE *input = NULL;
	char word[BUFF];
	char *ptr;

	if (argc != 2)
		ft_error(ERR_ARG);

	input = openread(argv, input);
	if (fscanf(input, "%s", word) > 0)
	{
		ptr = wordFormat(word);
		root = insert(root, hash(ptr), ptr);
	}
	while (fscanf(input, "%s", word) > 0)
	{
		ptr = wordFormat(ptr);
		insert(root, hash(ptr), ptr);
	}
	printf("%-11s %-10s %s\n", "hash", "key", "value");
	inorder(root);
	fclose(input);
	return 0;
}
