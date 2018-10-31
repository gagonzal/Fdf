# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 00:02:54 by gagonzal          #+#    #+#              #
#    Updated: 2018/07/12 00:27:13 by gagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
SRC = main.c  get_next_line.c init_map.c get_coord.c math_test.c #draw_map.c bresen_alg.c #math_test.c
FLAGS = #-Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointeur
INCLUDES = -I.
HEADER_H =  
LIB = -L./libft/ -lft -lm
OBJ = $(SRC:.c=.o)

all: $(NAME)

lib:
	@make -C ./libft 

$(NAME): $(HEADER_H) $(OBJ) lib
	@$(CC) $(OBJ) $(LIB) -o $(NAME) 
	@echo "LS binary \033[32mcreated\033[0m."

%.o: %.c $(HEADER_H)
	@echo "\033{[33mCOMPILING\033[0m" $<
	@$(CC) -o $@ -c $< $(INCLUDES)

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all
