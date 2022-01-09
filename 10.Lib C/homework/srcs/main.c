#include "../includes/libft.h"

int main(int argc, char *argv[])
{
	char *query;
	char *city_parse;
	CURL *curl_handle;
	CURLcode res;
	cJSON *request_json = NULL;
	cJSON *item = cJSON_CreateArray();

	if (argc != 2)
		ft_error(ERR_ARG);

	city_parse = ft_strdup(argv[1]);
	query = ft_query(city_parse);

	curl_handle = curl_easy_init();
	if (curl_handle)
	{
		ft_set_opts(curl_handle, query);
		res = curl_easy_perform(curl_handle);
		if (res != CURLE_OK)
			ft_error(ERR_CURL);

		int i = 0;
		request_json = cJSON_Parse(chunk.response);
		while (i < cJSON_GetArraySize(request_json))
		{
			item = cJSON_GetArrayItem(request_json, i++);
			ft_parse_json(item);
		}

		curl_easy_cleanup(curl_handle);
		free(chunk.response);
		free(city_parse);
		free(query);
	}
}
