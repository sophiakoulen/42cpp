# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:19:49 by skoulen           #+#    #+#              #
#    Updated: 2023/04/05 15:35:44 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifdef DEBUG
	CFLAGS+= -g3 -fsanitize=address
endif

NAME = program

FILES = main Animal Dog Cat WrongAnimal WrongCat
HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(addprefix objs/, $(FILES)))

objs/%.o: %.cpp
	mkdir -p objs
	$(CC) $(CFLAGS) -c -o $@ -I. $?

all: $(NAME)

$(NAME):	$(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
