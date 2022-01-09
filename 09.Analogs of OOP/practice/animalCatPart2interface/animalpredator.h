#ifndef _ANIMAL_PREDATOR_H_
#define _ANIMAL_PREDATOR_H_
#include <glib-2.0/glib-object.h>

G_BEGIN_DECLS

#define ANIMAL_TYPE_PREDATOR animal_predator_get_type()
G_DECLARE_INTERFACE(AnimalPredator, animal_predator, ANIMAL, PREDATOR, GObject)

struct _AnimalPredatorInterface
{
	GTypeInterface parent;
	void (*hunt)(AnimalPredator *);
	void (*eat_meat)(AnimalPredator *, int);
};

void animal_predator_hunt(AnimalPredator *self);

void animal_predator_eat_meat(AnimalPredator *self, int quantity);

G_END_DECLS

#endif /* _ANIMAL_PREDATOR_H_ */
