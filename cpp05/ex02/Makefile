# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:28:26 by skoulen           #+#    #+#              #
#    Updated: 2023/06/05 12:54:07 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
ifdef GPP
	CC = g++
endif

CFLAGS = -I. -Wall -Wextra -Werror -std=c++98
ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

NAME = program

CLASSES = Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm

SRCS = $(addsuffix .cpp, $(CLASSES)) main.cpp
HEADERS = $(addsuffix .hpp, $(CLASSES))

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
