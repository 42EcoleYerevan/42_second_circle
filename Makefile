SRCS = server.c\
	   client.c\
	   server_bonus.c\
	   client_bonus.c
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

bonus: $(LIBFT_A) client_bonus.o server_bonus.o
	$(CC) $(CFLAGS) client_bonus.o $(LIBS) -o client_bonus
	$(CC) $(CFLAGS) server_bonus.o $(LIBS) -o server_bonus

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT) bonus

clean: 
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f server
	rm -f client
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
