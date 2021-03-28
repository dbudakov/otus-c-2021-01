#include "../includes/libft.h"

int ft_cp1251(char *argv[])
{

	FILE *in_stream;
	FILE *to_stream;

	// Открытие файла в сторой кодировке, а именно cp1251
	if ((in_stream = fopen(argv[1], "r")) == NULL)
		ft_error(argv, errno);

	// Определение длины файла и создание буферного массива
	long int size_file;
	fseek(in_stream, 0, SEEK_END);
	size_file = ftell(in_stream);
	if (size_file == 0)
		ft_error(argv, 61);

	// Размер массива в 2 раза больше, так как все русские символы будут
	// занимать не 1 байт а 2, останется лишнее пространство,
	// но этим можно принебречь
	int buf[size_file * 2];
	fseek(in_stream, 0, SEEK_SET);

	// Изменение кодировки
	int a;		// используется для хранения считанного символа
	long int i; // "курсор" на входной массив(файл)
	long int j; // "курсор" на выходной массив
	for (i = 0, j = 0; i <= size_file; i++)
	{
		a = getc(in_stream);

		// Этот блок обрабатывает буквы от А-п,
		// далее разрядность значения меняется и нужно считать по другому
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

		// Этот блок переписывает все остальные значения
		// (не относящиеся к русским символам, которые от 192-255)
		else
		{
			buf[j] = a;
			j++;
		}
	}

	// Копирование буфера в строку, для реализации записи
	// за один шаг(через fputs), а не посимвольно(через fputc)
	char *buf_str;
	buf_str = (char *)calloc(1, sizeof(char));

	for (i = 0; buf[i] != EOF; i++)
	{
		buf_str = (char *)realloc(buf_str, (i + 1) * sizeof(char));
		*(buf_str + i) = buf[i];
	}

	// Check empty output_file
	if ((to_stream = fopen(argv[3], "a")) == NULL)
		ft_error(argv, errno);

	fseek(to_stream, 0, SEEK_END);
	size_file = ftell(to_stream);
	if (size_file != 0)
		ft_error(argv, 1);

	// Go in beginning file
	fseek(to_stream, 0, SEEK_SET);

	// Запись результата в файл
	fputs(buf_str, to_stream);

	// Заключительный блок
	free(buf_str);
	fclose(in_stream);
	fclose(to_stream);

	return 0;
}
