#include "../includes/libft.h"

/* sedzhvik_fundamentalnye_algoritmy_na_c,553 */
static size_t hashU(char *v, int M)
{
	size_t h, a = 31415, b = 27183;
	for (h = 0; *v != '\0'; v++, a = a * b % (M - 1))
		h = (a * h + *v) % M;
	return h;
}

size_t hash(char *v)
{
	unsigned int module = pow(2, 31) - 1;
	size_t h = hashU(v, module);
	return h;
}
