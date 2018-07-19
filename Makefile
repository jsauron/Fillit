# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 20:29:54 by tsisadag          #+#    #+#              #
#    Updated: 2018/05/17 16:02:57 by tsisadag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c mapping.c open_file.c parse_tetrimino.c solve.c str_tetrimino.c \
	  tools.c tools_2.c valid_tetrimino.c

HEADER_DIR = ./

FLAGS = -Wall -Wextra -Werror

C_NO	= "\033[35m"

DONE	= $(C_NO)fillit done.$(C_NO)
all : $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) -I $(HEADER_DIR)
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HEADER_DIR)
	@echo $(DONE)

clean: 
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
