#include <glib-2.0/glib.h>
#include <stdio.h>

// struct GArray {
//  gchar *data;
//  guint len;
// };

int main()
{
	GArray *a = g_array_new(FALSE, FALSE, sizeof(char *));
	char *first = "hello", *second = "there", *third = "world";
	g_array_append_val(a, first);
	g_array_append_val(a, second);
	g_array_append_val(a, third);
	printf("There are now %d items in the array\n", a->len);
	printf("The first item is '%s'\n", g_array_index(a, char *, 0));
	printf("The third item is '%s'\n", g_array_index(a, char *, 2));
	g_array_remove_index(a, 1);
	printf("There are now %d items in the array\n", a->len);
	g_array_free(a, TRUE);
}
