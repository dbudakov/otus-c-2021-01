#include <stdio.h>
#include <stdlib.h>

/* random for 100 + 50 value = 100-150  */
int main()
{

	int i = 0;
	srand(time(NULL));
	while (i < 100)
	{
		printf("rand: %ld\n", rand() % 50 + 100);
		i++;
	}
}
