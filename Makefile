NAME=a.out
CC=cc
CFLAGS=-Wall -Werror -Wextra
GNL=get_next_line
GNL_A=$(GNL)/libgnl.a
LIBFT=libft
LIBFT_A=$(LIBFT)/libft.a
MLX=minilibx-linux
MLX_A=$(MLX)/libmlx.a
SRCS=parse_map.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(GNL_A) $(MLX_A) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lXext -lX11 -o $(NAME)

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

fclean: clean
	rm -f $(NAME)
