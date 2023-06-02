CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = harl

FILES = main Harl
SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addprefix objs/, $(addsuffix .o, $(FILES)))
HEADERS = Harl.hpp

INCLUDE_PATHS = -I.

objs/%.o: %.cpp
	@if ! [ -d objs ]; then\
		mkdir objs;\
	fi
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE_PATHS) -o $@ $(SRCS)

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all