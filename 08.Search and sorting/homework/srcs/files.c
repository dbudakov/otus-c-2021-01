#include "../includes/libft.h"

FILE *openread(char *argv[], FILE *fp)
{
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		ft_error(argv, errno);
	return fp;
}
