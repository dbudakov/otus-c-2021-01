#include "./animalcat.h"

int main(int argc, char **argv)
{
	AnimalCat *cat_a = animal_cat_new();
	// AnimalCat *cat_b = animal_cat_new();
	animal_cat_say_meow(cat_a);
	return 0;
}
