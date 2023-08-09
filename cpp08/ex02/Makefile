# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 11:26:31 by skoulen           #+#    #+#              #
#    Updated: 2023/08/09 17:30:08 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

CC = c++
ifdef GPP
	CC = g++
endif

CFLAGS = -Wall -Wextra -Werror -std=c++98
ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

CLASSES =
SRCS = main.cpp $(addsuffix .cpp, $(CLASSES))

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
