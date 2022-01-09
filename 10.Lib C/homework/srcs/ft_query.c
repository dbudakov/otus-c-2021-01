#include "../includes/libft.h"

char *ft_query(char *city)
{
	char *query;

	query = calloc(strlen(WEATHER_SITE) + strlen(WEATHER_API) + strlen(WEATHER_QUERY) + strlen(city) + 1, 1);
	if (query == NULL)
		ft_error(ERR_MEM);
	query = strcat(query, WEATHER_SITE);
	query = strcat(query, WEATHER_API);
	query = strcat(query, WEATHER_QUERY);
	query = strcat(query, city);
	return query;
}
