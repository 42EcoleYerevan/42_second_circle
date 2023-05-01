NAME = server
SRCS = server.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./LIBFT
LIBFT_A = $(LIBFT)/libft.a


all: $(NAME)

%.c: %.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

clean: 
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
