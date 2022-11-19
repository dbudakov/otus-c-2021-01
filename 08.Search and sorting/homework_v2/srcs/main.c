#include "../includes/libft.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        ft_error(ERR_ARG);

    printf("%s\n", argv[0]);

    return 0;
}
