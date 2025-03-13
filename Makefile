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
