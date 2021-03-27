#include "../includes/libft.h"

void ft_error(char *argv[], int error)
{
	char *errorbuf;

	errorbuf = strerror(error);
	

	if (error == 2)
		fprintf(stderr, "%s: %s: %s\n",
		argv[0], argv[1], errorbuf);

	if (error == 5)
		fprintf(stderr, "%s: '%s' and '%s' are the same file\n",
		argv[0], argv[1], argv[3]);

	if (error == 13)
		fprintf(stderr, "%s: file '%s' or '%s': %s\n",
				argv[0], argv[1], argv[3], errorbuf);

	if (error == 22)
		fprintf(stderr, "%s: %s\n"
				"Try './to_utf8 <input_file> <encoding> <output_file>'\n",
				argv[0], errorbuf);

	if (error == 61)
		fprintf(stderr, "%s: %s: file is empty\n",
		argv[0], argv[1]);

	if (error == 1)
		fprintf(stderr, "%s: %s: file is not empty\n",
		argv[0], argv[3]);


	if (error == 95)
		fprintf(stderr, "%s: %s: %s\n"
				"encoding must be only: %s, %s, %s\n",
				argv[0], argv[2], errorbuf, CP1251, KOI8, ISO8859_5);

	exit(error);
}
