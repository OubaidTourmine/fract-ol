NAME = fract_ol
BONUS = fract_ol_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRC = fract_ol.c \
      fract_utils.c \
      fract_utils2.c \
      julia.c \
      julia_utils.c \
      mandelbrot.c

SRCS_BONUS = ./bonus/utils.c \
      		./bonus/julia_utils.c \
      		./bonus/bonus_fractal.c \
      		./bonus/cubic.c \
      		fract_utils.c \
			julia.c \
      		mandelbrot.c

OBJS = ${SRC:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${OBJS} ${CFLAGS} ${MLXFLAGS} -o ${NAME}
