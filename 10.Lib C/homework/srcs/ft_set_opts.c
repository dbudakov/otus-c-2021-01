#include "../includes/libft.h"

void ft_set_opts(CURL *curl_handle, char *query)
{
	curl_easy_setopt(curl_handle, CURLOPT_URL, query);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, cb);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
}
