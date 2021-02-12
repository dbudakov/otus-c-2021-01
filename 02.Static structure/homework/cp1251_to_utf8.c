#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Программа обрабатывает кодировки cp1251, с кодами от 192 до 255, это ряды А-Я, а-я, т.е.
 * русский алфавит без спец символов (ё,№ и.т.д),
 * https://ru.wikipedia.org/wiki/Windows-1251#/media/%D0%A4%D0%B0%D0%B9%D0%BB:Windows-1251-upper-half.gif
 */
int main(int argc, char *argv[])
{

	FILE *in_stream;
	FILE *to_stream;

	if (argc != 3)
	{
		printf("Недопустимый список параметров! Используйте:\n");
		printf("%s <Файл для обработки>\n", argv[0]);
		return -1;
	}

	// Открытие файла в сторой кодировке, а именно cp1251
	in_stream = fopen(argv[1], "r");
	if (in_stream == NULL)
	{
		printf("Ошибка при открытии файла '%s'\n", argv[1]);
		abort();
	}

	// Определение длины файла и создание буферного массива
	long int size_file;
	fseek(in_stream, 0, SEEK_END);
	size_file = ftell(in_stream);

	// Размер массива в 2 раза больше, так как все русские символы будут занимать не 1 байт а 2, останется лишнее пространство, но немного и этим принебрегаем
	int buf[size_file * 2];
	fseek(in_stream, 0, SEEK_SET);

	// Изменение кодировки
	int a;		// используется для хранения считанного символа
	long int i; // "курсор" на входной массив(файл)
	long int j; // "курсор" на выходной массив
	for (i = 0, j = 0; i <= size_file; i++)
	{
		a = getc(in_stream);

		// Этот блок обрабатывает буквы от А-п, далее разрядность значения меняется и нужно считать по другому
		if (a >= 192 && a <= 239)
		{
			buf[j] = 208;
			j++;

			buf[j] = 160 + (a - 208);
			j++;
		}

		// Этот блок обрабатывает символы от р-я
		else if (a >= 240 && a <= 255)
		{
			buf[j] = 209;
			j++;

			buf[j] = 97 + (a - 209);
			j++;
		}

		// Этот блок переписывает все остальные значения (не относящиеся к русским символам, которые от 192-255)
		else
		{
			buf[j] = a;
			j++;
		}
	}

	// Копирование буфера в строку, для реализации записи за один шаг(через fputs), а не посимвольно(через fputc)
	char *buf_str;
	buf_str = (char *)calloc(1, sizeof(char));

	for (i = 0; buf[i] != EOF; i++)
	{
		buf_str = (char *)realloc(buf_str, (i + 1) * sizeof(char));
		*(buf_str + i) = buf[i];
	}

	// Открытие файла для записи
	to_stream = fopen(argv[2], "w");
	if (to_stream == NULL)
	{
		printf("Ошибка при открытии файла '%s'\n", argv[2]);
		abort();
	}

	// Запись результата в файл
	fputs(buf_str, to_stream);

	// Заключительный блок
	free(buf_str);
	fclose(in_stream);
	fclose(to_stream);

	return 0;
}
