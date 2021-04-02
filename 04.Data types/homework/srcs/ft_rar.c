#include "../includes/libft.h"

int ft_get_eocd(FILE *fd, struct EOCD *S_EOCD)
{
	fseek(fd, -(EOCD_OFFSET), SEEK_END);
	fread(S_EOCD, sizeof(*S_EOCD), 1, fd);
	if (S_EOCD->signature != EOCD_SIGN)
		return 0;
	return 1;
}

// Переходим в конец jpeg файла и начало архива
int ft_end_jpeg(FILE *fd)
{

	int size_file;
	uint8_t TMP;
	uint8_t END_JPEG;

	fseek(fd, 1, SEEK_END);

	TMP = 0;
	size_file = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	while (size_file)
	{
		fread(&END_JPEG, 1, 1, fd);
		if (TMP == JPEG_END_SIGN_1)
			if (END_JPEG == JPEG_END_SIGN_2)
				return 1;
		TMP = END_JPEG;
		size_file--;
	}
	return 0;
}

// Перебираем записи центральныхй дирректрой и выводим наименование файла, для каждой
int ft_get_cr(FILE *fd, struct CentralDirectoryFileHeader *S_CR, struct EOCD *S_EOCD)
{
	int i;
	int len;

	fseek(fd, (S_EOCD->centralDirectoryOffset), SEEK_CUR);
	i = 0;
	while (i < S_EOCD->numberCentralDirectoryRecord)
	{

		fread(S_CR, sizeof(*S_CR), 1, fd);
		if (S_CR->signature != CR_SIGN)
			return 0;

		len = S_CR->filenameLength;
		while (len--)
			printf("%c", fgetc(fd));
		printf("\n");

		// 2 байта, как я понял являются замыкающей сигнатуроя,
		// которая уже является начлом следующей записи
		if (S_CR->extraFieldLength)
			fseek(fd, S_CR->extraFieldLength - 2, SEEK_CUR);

		if (S_CR->fileCommentLength)
			fseek(fd, S_CR->fileCommentLength, SEEK_CUR);
		i++;
	}
	// Считаем отсуп от конца файла, до последней Central Records
	//offset = (S_EOCD->sizeOfCentralDirectory / S_EOCD->totalCentralDirectoryRecord) + //EOCD_OFFSET;

	// Если частное с остатком добавить единицу
	//if (S_EOCD->sizeOfCentralDirectory % S_EOCD->totalCentralDirectoryRecord)
	//	offset++;

	return 1;
}

int ft_rar(char *argv[], int i)
{
	FILE *fd;
	struct EOCD S_EOCD;
	struct CentralDirectoryFileHeader S_CR;

	if ((fd = fopen(argv[i], "r")) == NULL)
		ft_error(argv, i, errno);

	if (ft_get_eocd(fd, &S_EOCD))
	{
		if (ft_end_jpeg(fd))
		{
			if (!(ft_get_cr(fd, &S_CR, &S_EOCD)))
				ft_error(argv, 1, ERR_BAD_RAR);
		}
		else
			ft_error(argv, i, ERR_NOT_JPEG);
	}
	else
		ft_error(argv, i, ERR_NOT_RAR);
	fclose(fd);
	return 0;
}
