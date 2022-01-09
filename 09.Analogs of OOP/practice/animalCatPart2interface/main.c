#include "animaltiger.h"
#include "animalpredator.h"

int main(int argc, char **argv)
{
	AnimalTiger *tiger = animal_tiger_new();
	animal_predator_hunt(tiger);
	animal_predator_eat_meat(tiger, 100500);
}
