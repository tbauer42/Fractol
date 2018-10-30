# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:10:45 by tbauer            #+#    #+#              #
#    Updated: 2018/10/30 20:32:07 by tbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

WARNINGS = -Werror -Wextra -Wall

LIB = -L  minilibx_macos -lmlx -framework OpenGL -framework AppKit -L Libft/ -lft  -I.

OBJC = aff.c julia.c main.c burning_ship.c fractol.c mandelbrot.c key.c mouse.c
OBJ = $(OBJC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx_macos
	@make -C Libft
	$(CC) $(WARNINGS) $(LIB) $(OBJ) -o $@

%.o: Rendu/%.c
	gcc -c $(WARNINGS) $< -o $@

clean:
	@make -C minilibx_macos clean
	@make -C Libft clean
	@rm -f $(OBJ)
	@echo 'removed .o'

fclean: clean
	@make -C minilibx_macos clean
	@make -C Libft fclean
	@rm -rf $(NAME) .depend
	@echo 'All your base are belong to us'

re: fclean all

.PHONY: all clean fclean re
