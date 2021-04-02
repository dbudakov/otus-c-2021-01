#define ERROR
#include "../includes/libft.h"

void ft_error(char *argv[], int i, int error)
{
	char *errorbuf;

	//printf("%d\n", error);

	errorbuf = strerror(error);
	if (error == ERR_NON_ARG)
		fprintf(stderr, "Usage: %s <file> ...\n", argv[0]);
	else if (error == ERR_NOT_RAR)
		fprintf(stderr, "%s: %s: Not RARJPEG file.\n", argv[0], argv[i]);
	else if (error == ERR_NOT_JPEG)
		fprintf(stderr, "%s: %s: Not JPEG file.\n", argv[0], argv[i]);
	else if (error == ERR_BAD_RAR)
		fprintf(stderr, "%s: %s: Bad archive\n", argv[0], argv[i]);
	else
		fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], errorbuf);

	exit(error);
}
