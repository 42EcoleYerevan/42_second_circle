SRCS = server.c\
	   client.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft
LIBFT_A = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft
NAME = leha

all: $(NAME)

$(NAME): $(LIBFT_A) server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: $(LIBFT_A) server.o
	$(CC) $(CFLAGS) server.o $(LIBS) -o server

client: $(LIBFT_A) client.o
	$(CC) $(CFLAGS) client.o $(LIBS) -o client

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

clean: 
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
