NAME=libgnl.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
SRCS = get_next_line.o \
	   get_next_line_utils.o
AR = ar r

$(NAME): $(SRCS)
	$(AR) $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(SRCS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all
