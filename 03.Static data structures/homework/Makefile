NAME := to_utf8
CC := gcc
FLAGS := -Wall -Wextra -Wpedantic -std=c11
FLAGS_C = ${FLAGS} -c

SRC_DIR := ./srcs/
SRC_FILES := ft_cp1251.c \
				ft_koi8.c \
				ft_error.c \
				ft_iso_8859_5.c \
				ft_check_encoding.c


SRC_S = $(addprefix ${SRC_DIR}, ${SRC_FILES})

MAIN_FILE := main.c
MAIN = $(addprefix ${SRC_DIR}, ${MAIN_FILE})

LIB_FILE := libft.a
LIB = $(addprefix ${SRC_DIR}, ${LIB_FILE})

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_S = $(addprefix ${SRC_DIR}, ${OBJ_FILES})

HEADERS := libft.h
HEADERS_DIR := ./includes/
HEADERS_TEMP = ${HEADERS_DIR}${HEADERS}.gch
ARCHIVE := ar rc
INDEX := ar -s
CLEAN := rm -rf

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${LIB}
	@${CC} ${FLAGS} ${MAIN} ${LIB} -o ${NAME}

#${NAME}:
#	cc srcs/add/ft_show.c includes/libft.h  srcs/ft_error.c

${LIB}: ${OBJ_S}
	@${ARCHIVE} $@ ${OBJ_S}
	@${INDEX} $@

${SRC_DIR}%.o: ${SRC_DIR}%.c
	@${CC} ${FLAGS_C} $< -o $@ -I ${HEADERS_DIR}

clean:
	@${CLEAN} ${OBJ_S} ${LIB} ${HEADERS_TEMP}

fclean: clean
	@${CLEAN} ${NAME}

re: fclean ${NAME}
	@${CLEAN} ${OBJ_S} ${LIB} ${HEADERS_TEMP}
