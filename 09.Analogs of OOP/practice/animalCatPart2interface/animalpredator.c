#include <stdio.h>
#include "animalpredator.h"

G_DEFINE_INTERFACE(AnimalPredator, animal_predator, G_TYPE_OBJECT)

static void animal_predator_default_init(AnimalPredatorInterface *iface)
{
	printf("The first instance of the object that implements AnimalPredator interface was created\n");
}

void animal_predator_hunt(AnimalPredator *self)
{
	AnimalPredatorInterface *iface = ANIMAL_PREDATOR_GET_IFACE(self);
	iface->hunt(self);
}

void animal_predator_eat_meat(AnimalPredator *self, int quantity)
{
	AnimalPredatorInterface *iface = ANIMAL_PREDATOR_GET_IFACE(self);
	iface->eat_meat(self, quantity);
}
