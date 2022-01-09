#include <stdio.h>

#include "./animaltiger.h"
#include "./animalpredator.h"

static void animal_tiger_predator_interface_init(AnimalPredatorInterface *iface);

struct _AnimalTiger
{
	AnimalCat parent;
};

G_DEFINE_TYPE_WITH_CODE(AnimalTiger, animal_tiger, ANIMAL_TYPE_CAT, G_IMPLEMENT_INTERFACE(ANIMAL_TYPE_PREDATOR, animal_tiger_predator_interface_init))

static void animal_tiger_predator_hunt(AnimalTiger *self)
{
	printf("Tiger hunts. Beware!\n");
}

static void animal_tiger_predator_eat_meat(AnimalTiger *self, int quantity)
{
	printf("Tiger eats %d kg of meat.\n", quantity);
}

static void animal_tiger_predator_interface_init(AnimalPredatorInterface *iface)
{
	iface->hunt = animal_tiger_predator_hunt;
	iface->eat_meat = animal_tiger_predator_eat_meat;
}

static void animal_tiger_real_say_meow(AnimalTiger *self)
{
	printf("Tiger say: ARRRRGH!!!\n");
}

static void animal_tiger_class_init(AnimalTigerClass *self)
{
	printf("First instance of AnimalTiger was created.\n");
	AnimalCatClass *parent_class = ANIMAL_CAT_CLASS(self);
	parent_class->say_meow = animal_tiger_real_say_meow;
}

static void animal_tiger_init(AnimalTiger *self)
{
	printf("Tiger cub was born.\n");
}

AnimalTiger *animal_tiger_new()
{
	return g_object_new(ANIMAL_TYPE_TIGER, NULL);
}
