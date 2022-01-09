/*obj.c*/
#include "./obj.h"

struct obj_t
{
	int id;
};

obj_t *obj_alloc()
{
	obj_t *result = (obj_t *)malloc(sizeof(obj_t));
	result->id = 0;
	return result;
}

void obj_setid(obj_t *o, int i)
{
	o->id = i;
}

int obj_getid(obj_t *o)
{
	return o->id;
}

void obj_free(obj_t *o)
{
	free(o);
}
