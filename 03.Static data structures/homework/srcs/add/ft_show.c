#include "../../includes/libft.h"
#include "unistd.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	FILE *in_stream;
	char sym;
	int size;
	int i;

	sym = 1;
	if (argc < 2)
		return (1);
	if ((in_stream = fopen(argv[1], "r")) == 0)
		ft_error(argv, errno);
	fseek(in_stream, 0, SEEK_END);
	size = ftell(in_stream);
	fseek(in_stream, 0, SEEK_SET);
	i = 0;
	while (i++ <= size)
	{
		printf("%d ", getc(in_stream));
	}
	printf("\n");
	fclose(in_stream);
	return (0);
}
