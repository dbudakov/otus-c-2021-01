#include "../includes/libft.h"

int ft_check(int i, char *argv[])
{
	struct stat s;

	if (stat(argv[i], &s) == 0)
		if (S_ISREG(s.st_mode))
			;
		else if (S_ISDIR(s.st_mode))
			ft_error(argv, i, EISDIR);
		else
			ft_error(argv, i, EINVAL);
	else
		ft_error(argv, i, errno);

	return 1;
}
