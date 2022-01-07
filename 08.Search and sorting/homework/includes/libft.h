#ifndef LIBFT_H
#define LIBFT_H

#define ERR_MAX_CODE 132
#define BUFF 250
#define FORMAT ";"
#define PROG_NAME "sorting"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#include <string.h>
#include <locale.h>

struct node
{
	int index;
	int value;
	char *key;
	struct node *left;
	struct node *right;
};

size_t hash(char *v);
void ft_error(size_t error);

char *ft_strdup(char *str);
char *trimprefix(char *str, char *szwcstr);
char *trimsuffix(char *str, char *szwcstr);
char *wordFormat(char *str);
FILE *openread(char *argv[], FILE *fp);

struct node *insert(struct node *root, int index, char *key);
void inorder(struct node *root);
struct node *createNode(int index, char *key);

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
