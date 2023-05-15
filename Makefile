# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agladkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 13:28:59 by agladkov          #+#    #+#              #
#    Updated: 2023/05/15 13:55:38 by agladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=cc
CFLAGS=-Wall -Werror -Wextra
GNL=get_next_line
GNL_A=$(GNL)/libgnl.a
LIBFT=libft
LIBFT_A=$(LIBFT)/libft.a
SRC=linal.c \
	project.c \
	proc.c \
	draw.c \
	draw_map.c \
	keyboard.c \
	mouse_hook.c \
	init.c \
	parse_map.c \
	parser_utils.c \
	parser_utils2.c \
	utils.c \
	main.c
SRCS=$(addprefix  ./src/, $(SRC))
OBJS=$(SRCS:%.c=%.o)
HEADER=fdf.h
COMPILE=$(CC) $(CFLAGS) $(OBJS) \
	   	-L$(LIBFT) -lft \
	   	-L$(GNL) -lgnl \
	   	-lmlx \
	   	-framework OpenGL \
		-framework AppKit \
		-lm -o $(NAME)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(GNL_A) $(OBJS)
	$(COMPILE)
	
$(GNL_A):
	@$(MAKE) -C $(GNL)
	@echo 'Compiled libgnl.a'

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)
	@echo 'Compiled libft.a'

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(GNL) clean
	@echo 'clean gnl'
	@$(MAKE) -C $(LIBFT) clean
	@echo 'clean libft'

fclean: clean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: clean fclean all
