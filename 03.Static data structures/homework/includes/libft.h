#ifndef LIBFT_H

# define CP1251		"cp-1251"
# define KOI8		"koi8"
# define ISO8859_5	"iso-8859-5"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

int		ft_cp1251(char *argv[]);
int		ft_check_encoding(char *str);
void	ft_error(char *argv[], int error);


#endif
