UNAME=$(shell uname)
ifeq ($(UNAME),Linux)
	MLX=minilibx-linux
	MLX_A=$(MLX)/libmlx.a
else
	MLX=minilibx
	MLX_A=$(MLX)/libmlx.a
endif
NAME=a.out
CC=cc
CFLAGS=-Wall -Werror -Wextra
GNL=get_next_line
GNL_A=$(GNL)/libgnl.a
LIBFT=libft
LIBFT_A=$(LIBFT)/libft.a
SRCS=parse_map.c \
	 utils.c
OBJS=$(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(GNL_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lXext -lX11 -o $(NAME)
	rm -f $(OBJS)

$(GNL_A):
	@$(MAKE) -s -C $(GNL)
	@echo 'Compiled libgnl.a'

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo 'Compiled libft.a'

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo 'Compiled  libmlx.a'

all: 
	$(NAME)

clean:
	@$(MAKE) clean -s -C $(GNL)
	@echo 'clean gnl'
	@$(MAKE) clean -s -C $(LIBFT)
	@echo 'clean libft'
	@$(MAKE) clean -s -C $(MLX)
	@echo 'clean mlx'
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
