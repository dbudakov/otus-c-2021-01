#include "../includes/libft.h"

char *trimprefix(char *str, char *szwcstr)
{
	int i;
	int end;

	if (!str)
		return 0;
	i = 0;
	end = strlen(str);
	while (i < end && strchr(szwcstr, str[i]))
		str[i++] = '\0';
	return &str[i];
}

char *trimsuffix(char *str, char *szwcstr)
{
	int i;

	if (!str)
		return 0;
	i = strlen(str) - 1;
	while (i >= 0 && strchr(szwcstr, str[i]))
		str[i--] = '\0';
	return str;
}
