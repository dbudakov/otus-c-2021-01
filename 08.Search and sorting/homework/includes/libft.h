#ifndef LIBFT_H
#define LIBFT_H

#define BUFF 250
#define FORMAT ";"
#define PROG_NAME "sorting"
#define ERR_MAX_CODE 132

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#include <string.h>
#include <locale.h>

struct node;

size_t hash(char *v);
void ft_error(size_t error);

char *ft_strdup(char *str);
char *wordFormat(char *str);
FILE *openread(char *argv[], FILE *fp);

struct node *insert(struct node *root, int index, char *key);
void inorder(struct node *root);
struct node *createNode(int index, char *key);

enum l_ERROR
{
	ERR_ARG = 132,
};

struct node
{
	int index;
	int value;
	char *key;
	struct node *left;
	struct node *right;
};

#endif
