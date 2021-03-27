#include "../includes/libft.h"

/*
 * Программа обрабатывает кодировки cp1251, с кодами от 192 до 255, 
 * это ряды А-Я, а-я, т.е.
 * русский алфавит без спец символов (ё,№ и.т.д),
 * 
 * https://ru.wikipedia.org/wiki/Windows-1251#/media/\
 * %D0%A4%D0%B0%D0%B9%D0%BB:Windows-1251-upper-half.gif
 */

int	main(int argc, char *argv[])
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
			printf("koi8\n");
		else if (encoding == 3)
			printf("iso-8859-01\n");
		else
			ft_error(argv, 95);
	}
	else
		ft_error(argv, 22);
	return (0);
}
