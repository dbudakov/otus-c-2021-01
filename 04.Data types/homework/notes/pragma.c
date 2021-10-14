/* Приведение размера структуры, до четного значения, здесь расширение char до 2 байт */
#include <stdio.h>

#pragma pack(push, 1)
typedef struct
{
    unsigned char x;
    unsigned short y;
    unsigned int z;
} my_arg_t_pragma;
#pragma pack(pop)

typedef struct
{
    unsigned char x;
    unsigned short y;
    unsigned int z;
} my_arg_t_without_pragma;


int main(){
    printf("size of data is %d\n", sizeof(my_arg_t_pragma));
    printf("size of data is %d\n", sizeof(my_arg_t_without_pragma));
}