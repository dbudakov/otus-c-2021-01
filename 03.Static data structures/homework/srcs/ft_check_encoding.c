#include "../includes/libft.h"

int ft_check_encoding(char *str)
{
	if (strcmp(str, CP1251) == 0)
		return E_CP1251;
	else if (strcmp(str, KOI8) == 0)
		return E_KOI8;
	else if (strcmp(str, ISO8859_5) == 0)
		return E_ISO8859_5;
	return 0;
}
