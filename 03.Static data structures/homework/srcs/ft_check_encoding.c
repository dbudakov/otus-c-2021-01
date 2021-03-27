#include "../includes/libft.h"

int ft_check_encoding(char *str)
{
	if (strcmp(str, CP1251) == 0)
		return (1);
	else if (strcmp(str, KOI8) == 0)
		return (2);
	else if (strcmp(str, ISO8859_5) == 0)
		return (3);
	return (0);
}
