#include "../includes/libft.h"

void ft_error(size_t error)
{
	if (error == ERR_MEM)
		fprintf(stderr, "%s: memory out\n", PROG_NAME);
	else if (error == ERR_CURL)
		fprintf(stderr, "%s: error request\n", PROG_NAME);
	else if (error == ERR_ARG)
		fprintf(stderr, "Usage: ./%s \"<city>\"\n", PROG_NAME);
	else if (error < ERR_MAX_CODE)
		fprintf(stderr, "%s: %s\n", PROG_NAME, strerror(error));
	exit(error);
}
