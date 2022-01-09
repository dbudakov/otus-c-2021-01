/* obj.h */
#ifndef OBJ_H
#define OBJ_H

#include <stdlib.h>
#include <stdio.h>

typedef struct obj_t obj_t;

obj_t *obj_alloc();
void obj_setid(obj_t *, int);
int obj_getid(obj_t *);
void obj_free(obj_t *);

#endif
