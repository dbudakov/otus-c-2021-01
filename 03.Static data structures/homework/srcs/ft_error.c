#define ERROR
#include "../includes/libft.h"

void ft_error(char *argv[], int error)
{
	char *errorbuf;

	errorbuf = strerror(error);
	if (error == ERR_SRC_FILE)
		fprintf(stderr, "%s: %s: %s\n",
				argv[0], argv[1], errorbuf);
	if (error == ERR_DEST_FILE)
		fprintf(stderr, "%s: %s: %s\n",
				argv[0], argv[3], errorbuf);
	if (error == ERR_SAME_FILE)
		fprintf(stderr, "%s: '%s' and '%s' are the same file\n",
				argv[0], argv[1], argv[3]);
	if (error == ERR_PERMISSION)
		fprintf(stderr, "%s: file '%s' or '%s': %s\n",
				argv[0], argv[1], argv[3], errorbuf);
	if (error == ERR_ARG)
		fprintf(stderr, "%s: %s\n"
						"Try './to_utf8 <input_file> <encoding> <output_file>'\n",
				argv[0], errorbuf);
	if (error == ERR_EMPTY_FILE)
		fprintf(stderr, "%s: %s: file is empty\n",
				argv[0], argv[1]);
	if (error == ERR_ENCODING)
		fprintf(stderr, "%s: %s: %s\n"
						"encoding must be only: %s, %s, %s\n",
				argv[0], argv[2], errorbuf, CP1251, KOI8, ISO8859_5);
	exit(error);
}
