/*main.c*/
#include "./obj.h"

int main()
{
	obj_t *obj = obj_alloc();
	obj_setid(obj, 42);
	printf("%d\n", obj_getid(obj));
	obj_free(obj);
	return 0;
}
