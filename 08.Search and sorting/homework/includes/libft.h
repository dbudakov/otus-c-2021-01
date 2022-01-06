#ifndef LIBFT_H
#define LIBFT_H

#define ERR_MAX_CODE 132
#define BUFF 250
// #define ERROR
// #define ERR_ARG "./sorgting <file>"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#include <string.h>
#include <locale.h>

size_t hash(char *v);
void ft_error(char *argv[], size_t error);

char *trimprefix(char *str, char *szwcstr);
char *trimsuffix(char *str, char *szwcstr);

FILE *openread(char *argv[], FILE *fp);

enum l_ERROR
{
	ERR_ARG = 132,
	// ERR_SAME_FILE = 5,
	// ERR_PERMISSION = 13,
	// ERR_ARG = 22,
	// ERR_EMPTY_FILE = 61,
	// ERR_ENCODING = 95
};

#endif
