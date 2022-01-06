#ifndef LIBFT_H
#define LIBFT_H

#define EOCD_SIGN 0x06054B50
#define CR_SIGN 0x02014B50
#define EOCD_OFFSET 22
#define JPEG_END_SIGN_1 0xFF
#define JPEG_END_SIGN_2 0xD9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

# ifdef ERROR 
unsigned int g_error = 0;

# else
extern unsigned int g_error;

# endif

void ft_error(char *argv[], int i, int error);
int ft_check(int i, char *argv[]);
int ft_rar(char *argv[], int i);

enum l_ERROR
{
	ERR_FILE = 2,
	ERR_NON_ARG = 134,
	ERR_TYPE = 135,
	ERR_NOT_RAR = 136,
	ERR_NOT_JPEG = 137,
	ERR_BAD_RAR = 138

};

#pragma pack(1)
struct EOCD
{
	// Обязательная сигнатура, равна 0x06054b50
	uint32_t signature;
	// Номер диска
	uint16_t diskNumber;
	// Номер диска, где находится начало Central Directory
	uint16_t startDiskNumber;
	// Количество записей в Central Directory в текущем диске
	uint16_t numberCentralDirectoryRecord;
	// Всего записей в Central Directory
	uint16_t totalCentralDirectoryRecord;
	// Размер Central Directory
	uint32_t sizeOfCentralDirectory;
	// Смещение Central Directory
	uint32_t centralDirectoryOffset;
	// Длина комментария
	uint16_t commentLength;
	// Комментарий (длиной commentLength)
	//uint8_t *comment;
};

struct CentralDirectoryFileHeader
{
	// Обязательная сигнатура, равна 0x02014b50
	uint32_t signature;
	// Версия для создания
	uint16_t versionMadeBy;
	// Минимальная версия для распаковки
	uint16_t versionToExtract;
	// Битовый флаг
	uint16_t generalPurposeBitFlag;
	// Метод сжатия (0 - без сжатия, 8 - deflate)
	uint16_t compressionMethod;
	// Время модификации файла
	uint16_t modificationTime;
	// Дата модификации файла
	uint16_t modificationDate;
	// Контрольная сумма
	uint32_t crc32;
	// Сжатый размер
	uint32_t compressedSize;
	// Несжатый размер
	uint32_t uncompressedSize;
	// Длина название файла
	uint16_t filenameLength;
	// Длина поля с дополнительными данными
	uint16_t extraFieldLength;
	// Длина комментариев к файлу
	uint16_t fileCommentLength;
	// Номер диска
	uint16_t diskNumber;
	// Внутренние аттрибуты файла
	uint16_t internalFileAttributes;
	// Внешние аттрибуты файла
	uint32_t externalFileAttributes;
	// Смещение до структуры LocalFileHeader
	uint32_t localFileHeaderOffset;
	// Имя файла (длиной filenameLength)
	//uint8_t *filename;
	// Дополнительные данные (длиной extraFieldLength)
	//uint8_t *extraField;
	// Комментарий к файла (длиной fileCommentLength)
	//uint8_t *fileComment;
};

#endif
