#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	FILE *to_stream;

	if (argc != 2)
		return (1);
	if ((to_stream = fopen(argv[1], "w")) == NULL)
		return (1);
	i = 0;
	while (i < 256)
	{
		fputc(i++, to_stream);
	}
	fclose(to_stream);
	return (0);
}
