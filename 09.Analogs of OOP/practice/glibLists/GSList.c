#include <glib-2.0/glib.h>
#include <stdio.h>

// struct GSList
// {
// 	gpointer data;
// 	GSList *next;
// };

int main()
{
	GSList *list = NULL, *iterator = NULL;
	list = g_slist_append(list, "second");
	list = g_slist_prepend(list, "first");
	list = g_slist_append(list, "third");
	list = g_slist_append(list, "fourth");
	printf("The list is now %d items long\n", g_slist_length(list));
	list = g_slist_remove(list, "first");
	printf("The list is now %d items long\n", g_slist_length(list));
	printf("The last item is '%s'\n", g_slist_last(list)->data);
	printf("The item at index '1' is '%s'\n", g_slist_nth(list, 1)->data);
	printf("Now the item at index '1' the easy way: '%s'\n",
				 g_slist_nth_data(list, 1));
	printf("And the 'next' item after first item is '%s'\n",
				 g_slist_next(list)->data);
	for (iterator = list; iterator; iterator = iterator->next)
	{
		printf("Current item is '%s'\n", iterator->data);
	}
	g_slist_free(list);
}
