#ifndef LIBFT_H
#define LIBFT_H

#define PROG_NAME "sorting"
#define ERR_MAX_CODE 132

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include <errno.h>

#include <string.h>
// #include <locale.h>


size_t hash(char *v);
void ft_error(size_t error);

enum l_ERROR
{
	ERR_ARG = 132,
};


#endif
