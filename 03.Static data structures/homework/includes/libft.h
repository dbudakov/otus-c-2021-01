#ifndef LIBFT_H
#define LIBFT_H

#define CP1251 "cp1251"
#define KOI8 "koi8"
#define ISO8859_5 "iso-8859-5"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int ft_cp1251(char *argv[]);
int ft_koi8(char *argv[]);
int ft_iso_8859_5(char *argv[]);
int ft_check_encoding(char *str);
void ft_error(char *argv[], int error);

#ifdef CP_1251
unsigned char cp_1251[] = {
	144, 145, 146, 147, 148, 149, 150, 151, 152, 153,
	154, 155, 156, 157, 158, 159, 160, 161, 162, 163,
	164, 165, 166, 167, 168, 169, 170, 171, 172, 173,
	174, 175, 176, 177, 178, 179, 180, 181, 182, 183,
	184, 185, 186, 187, 188, 189, 190, 191, 128, 129,
	130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
	140, 141, 142, 143};
//#else
//extern unsigned char cp_1251[];
#endif

#ifdef KOI_8
unsigned char koi8[] = {
	142, 176, 177, 134, 180, 181, 132, 179, 133, 184,
	185, 186, 187, 188, 189, 190, 191, 143, 128, 129,
	130, 131, 182, 178, 140, 139, 183, 136, 141, 137,
	135, 138, 174, 144, 145, 166, 148, 149, 164, 147,
	165, 152, 153, 154, 155, 156, 157, 158, 159, 175,
	160, 161, 162, 163, 150, 146, 172, 171, 151, 168,
	173, 169, 167, 170};
//#else
//extern unsigned char koi8[];
#endif

#ifdef ISO_8859_5
unsigned char iso_8859_5[] = {
	144, 145, 146, 147, 148, 149, 150, 151, 152, 153,
	154, 155, 156, 157, 158, 159, 160, 161, 162, 163,
	164, 165, 166, 167, 168, 169, 170, 171, 172, 173,
	174, 175, 176, 177, 178, 179, 180, 181, 182, 183,
	184, 185, 186, 187, 188, 189, 190, 191, 128, 129,
	130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
	140, 141, 142, 143};
//#else
//extern unsigned char iso_8859_5[];
#endif

enum l_ERROR
{
	ERR_SRC_FILE = 1,
	ERR_DEST_FILE = 3,
	ERR_SAME_FILE = 5,
	ERR_PERMISSION = 13,
	ERR_ARG = 22,
	ERR_EMPTY_FILE = 61,
	ERR_ENCODING = 95
};

enum ENCODING
{
	E_ERR,
	E_CP1251,
	E_KOI8,
	E_ISO8859_5
};

#endif
