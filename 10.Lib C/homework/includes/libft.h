#ifndef LIBFT_H
#define LIBFT_H

#define WEATHER_SITE "https://www.metaweather.com"
#define WEATHER_API "/api/location/search/"
#define WEATHER_QUERY "?query="
#define PROG_NAME "wheater"
#define ERR_MAX_CODE 132

#include <cjson/cJSON.h>
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

typedef struct memory
{
	char *response;
	size_t size;
} chunk_s;

void ft_error(size_t error);
char *ft_query(char *city);
void ft_parse_json(cJSON *item);
char *ft_strdup(char *str);
void ft_set_opts(CURL *curl_handle, char *query);
size_t cb(void *data, size_t size, size_t nmemb, void *userp);

enum l_ERROR
{
	ERR_ARG = 132,
	ERR_CURL = 133,
	ERR_MEM = 134
};

extern chunk_s chunk;

#endif
