# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 19:07:41 by aamaral-          #+#    #+#              #
#    Updated: 2023/06/29 19:07:48 by aamaral-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11

SRC = fractol.c \
	fractals.c \
	hooks.c \
	params.c \
	
BSRC = fractol_bonus.c \
	fractals_bonus.c \
	hooks_bonus.c \
	params_bonus.c \

all: $(NAME)

$(NAME):$(SRC:.c=.o) fractol.h
	$(CC) $(CFLAGS) -lm $(SRC) $(MLXFLAGS) -o $(NAME)

clean:
	$(RM) $(SRC:.c=.o) $(BSRC:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:$(BSRC:.c=.o) fractol_bonus.h
	$(CC) $(CFLAGS) -lm $(BSRC) $(MLXFLAGS) -o $(NAME)

.PHONY: all, clean, fclean, re
