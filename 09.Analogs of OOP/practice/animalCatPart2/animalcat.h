#ifndef _ANIMAL_CAT_H_
#define _ANIMAL_CAT_H_
#include <glib-2.0/glib-object.h>

G_BEGIN_DECLS

/* все наши дальнейшие определения будут тут                             */
/* #define OURNAMESPACE_TYPE_OUROBJECT ournamespace_ourobject_get_type() */
/* return Gtype structure, include type info, name, size, links initial and finalyze*/
#define ANIMAL_TYPE_CAT animal_cat_get_type()

/*G_DECARE_DERIVABLE_TYPE (NamespaceObject, namespace_object, NAMESPACE, OBJECT, ParentClass)*/
/*update type, check type, */
G_DECLARE_DERIVABLE_TYPE(AnimalCat, animal_cat, ANIMAL, CAT, GObject)

struct _AnimalCatClass
{
	GObjectClass parent_class;
	void (*say_meow)(AnimalCat *);
};

/* g_object_new(NAMESPACE_TYPE_OBJECT, NULL);*/
AnimalCat *animal_cat_new();

void animal_cat_say_meow(AnimalCat *self);

G_END_DECLS

#endif /* _ANIMAL_CAT_H_ */
