NAME := weather
CC := gcc
LD_CURL = `curl-config --libs`
LD_JSON = `pkg-config --cflags --libs libcjson`
FLAGS := -Wall -Wextra -Wpedantic -std=c11 ${LD_CURL} ${LD_JSON}
FLAGS_C = ${FLAGS} -c

SRC_DIR := ./srcs/
SRC_FILES := ft_string.c \
						ft_query.c \
						ft_parse_curl.c \
						ft_parse_json.c \
						ft_set_opts.c \
						ft_error.c

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
