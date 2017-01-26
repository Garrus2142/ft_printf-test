# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 23:08:09 by thugo             #+#    #+#              #
#    Updated: 2017/01/26 18:30:46 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf_test
SRC = src/main.c src/tests_normal.c src/tests_undefined.c src/capture_stdout.c
INCLUDE_DIR = ./includes
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -Wno-format -I $(INCLUDE_DIR) -o $(NAME) $(OBJ) -L. -lftprintf

%.o: %.c
	gcc -Wno-format -I $(INCLUDE_DIR) -c $^ -o $@

clean: fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)
