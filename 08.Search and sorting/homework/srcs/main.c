#include "../includes/libft.h"

int main(int argc, char *argv[])
{

	FILE *input = NULL;
	char w[BUFF];

	if (argc != 2)
		ft_error(argv, ERR_ARG);

	input = openread(argv, input);
	fscanf(input, "%s", w);

	return 0;
}
