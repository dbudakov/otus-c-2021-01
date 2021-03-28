#include "../includes/libft.h"

int main(int argc, char *argv[])
{

	int encoding;

	if (argc == 4)
	{
		if (strcmp(argv[1], argv[3]) == 0)
			ft_error(argv, 5);

		encoding = ft_check_encoding(argv[2]);
		if (encoding == 1)
			ft_cp1251(argv);
		else if (encoding == 2)
			ft_koi8(argv);
		else if (encoding == 3)
			ft_iso_8859_5(argv);
		else
			ft_error(argv, 95);
	}
	else
		ft_error(argv, 22);
	return (0);
}
