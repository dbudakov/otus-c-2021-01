#include "../includes/libft.h"

void ft_parse_json(cJSON *item)
{
	cJSON *city = cJSON_GetObjectItem(item, "title");
	cJSON *location_type = cJSON_GetObjectItem(item, "location_type");
	cJSON *woeid = cJSON_GetObjectItem(item, "woeid");
	cJSON *latt_long = cJSON_GetObjectItem(item, "latt_long");
	char *cityOutput = cJSON_Print(city);
	char *locationTypeOutput = cJSON_Print(location_type);
	char *woeidOutput = cJSON_Print(woeid);
	char *lattLongOutput = cJSON_Print(latt_long);
	printf("%s, %s, %s, %s\n", locationTypeOutput, cityOutput, woeidOutput, lattLongOutput);
}
