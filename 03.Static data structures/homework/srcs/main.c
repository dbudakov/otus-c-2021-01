#include "../includes/libft.h"

int main(int argc, char *argv[])
{

	int encoding;

	if (argc == 4)
	{
		if (strcmp(argv[1], argv[3]) == 0)
			ft_error(argv, ERR_SAME_FILE);

		encoding = ft_check_encoding(argv[2]);
		if (encoding == E_CP1251)
			ft_cp1251(argv);
		else if (encoding == E_KOI8)
			ft_koi8(argv);
		else if (encoding == E_ISO8859_5)
			ft_iso_8859_5(argv);
		else
			ft_error(argv, ERR_ENCODING);
	}
	else
		ft_error(argv, ERR_ARG);
	return 0;
}
