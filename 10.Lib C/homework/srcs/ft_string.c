#include "../includes/libft.h"

static int isnchar(char c)
{
	if (c > 64 && c < 91)
		return 0;
	if (c > 96 && c < 123)
		return 0;
	return 1;
}

static int first_chr(char *str)
{
	int i = 0;
	while (isnchar(str[i]))
		i++;
	return i;
}

static int last_chr(char *str)
{
	int i = strlen(str) - 1;
	while (isnchar(str[i]))
		i--;
	return i;
}

char *ft_strdup(char *str)
{
	int i = 0;
	int c = 0;
	char *dup;
	int beg = first_chr(str);
	int end = last_chr(str) + 1;

	while (str[c] != '\0')
	{
		if (str[c] == ' ')
			c = c + 2;
		c++;
	}
	dup = (char *)malloc(c + 1);

	i = 0;
	int j = beg;
	while (str[j] != '\0' && j != end)
	{
		if (str[j] == ' ')
		{
			dup[i++] = '%';
			dup[i++] = '2';
			dup[i] = '0';
		}
		else
			dup[i] = str[j];
		i++;
		j++;
	}
	dup[i] = '\0';
	return dup;
}
