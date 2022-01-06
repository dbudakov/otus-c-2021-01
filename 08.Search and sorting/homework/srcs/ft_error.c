#include "../includes/libft.h"

void ft_error(char *argv[], size_t error)
{
	// char *errorbuf;
	// errorbuf = strerror(error);
	if (error < ERR_MAX_CODE)
		fprintf(stderr, "%s: %s\n", argv[0], strerror(error));
	else if (error == ERR_ARG)
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	exit(error);
}
