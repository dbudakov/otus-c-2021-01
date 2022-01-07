#include "../includes/libft.h"

void ft_error(size_t error)
{
	// char *errorbuf;
	// errorbuf = strerror(error);
	if (error < ERR_MAX_CODE)
		fprintf(stderr, "%s: %s\n", PROG_NAME, strerror(error));
	else if (error == ERR_ARG)
		fprintf(stderr, "Usage: %s <filename>\n", PROG_NAME);
	exit(error);
}
