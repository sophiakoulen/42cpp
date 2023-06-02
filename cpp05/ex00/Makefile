# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:28:26 by skoulen           #+#    #+#              #
#    Updated: 2023/06/02 16:33:29 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -I. -Wall -Wextra -Werror -std=c++98

NAME = program

CLASSES = Bureaucrat

SRCS = $(addsuffix .cpp, $(CLASSES))
HEADERS = $(addsuffix .hpp, $(CLASSES))

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

$(NAME): $(OBJS) main.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) main.o 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
