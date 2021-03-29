#include <string.h>
#include <stdio.h>
#include <iconv.h>
#include <stdlib.h>

int main()
{
	int k;
	unsigned char *str;
	int a;

	str = (char *)malloc(1024);
	a = 0;
	k = 0;
	while (k < 256)
		str[a++] = k++;
	str[a] = '\0';

	unsigned char *in = "Вопрос!";
	unsigned char out[1024];

	/* ! */
	char *in_ptr = in;
	char *out_ptr = &out[0];

	size_t inbytes = strlen(in);
	size_t outbytes = sizeof out;

	// определяется элемент cd,
	// а также выполняется конвертация из UTF-8 в нужную кодировку
	//iconv_t cd = iconv_open("cp1251", "utf-8");
	iconv_t cd = iconv_open("koi8-r", "utf-8");
	//iconv_t cd = iconv_open("iso-8859-5", "utf-8");

	// подается cd, указатель на строку с входными данными,
	// указатель на переменную с размером,
	// указатель на выходной буфер и выходной размер
	iconv(cd, &in_ptr, &inbytes, &out_ptr, &outbytes);
	iconv_close(cd);

	// Блок для вывода результатов
	int i;
	int len;
	len = strlen(out);

	// Вывод числово значения
	for (i = 0; i < len; i++)
		printf("%d ", out[i]);
	printf("\n");

	// Вывод символьного значения
	for (i = 0; i < len; i++)
		printf("%c ", out[i]);
	printf("\n");
	free(str);
}
