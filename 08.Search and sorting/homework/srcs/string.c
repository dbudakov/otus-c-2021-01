#include "../includes/libft.h"

char *trimprefix(char *str, char *szwcstr)
{
	int i;
	int end;

	if (!str)
		return NULL;
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
		return NULL;
	i = strlen(str) - 1;
	while (i >= 0 && strchr(szwcstr, str[i]))
		str[i--] = '\0';
	return str;
}

char *ft_strdup(char *str)
{
	int i;
	char *dup;
	if (!str)
		return NULL;

	i = 0;
	dup = (char *)malloc(strlen(str) + 1);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	i++;
	dup[i] = '\0';
	return dup;
}

char *wordFormat(char *str)
{
	trimprefix(str, FORMAT);
	trimsuffix(str, FORMAT);
	return str;
}
