NAME = push_swap
NAMEB = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c\
	   push_swap_utils.c\
	   push_swap_utils2.c\
	   push_swap_utils3.c\
	   push_swap_list_utils.c\
	   push_swap_sort.c\
	   push_swap_sort_utils.c\
	   push_swap_sort_numbers.c\
	   push_swap_check.c
SRCB = push_swap.c\
	   push_swap_utils.c\
	   push_swap_utils2.c\
	   push_swap_utils3.c\
	   push_swap_list_utils.c\
	   push_swap_sort.c\
	   push_swap_sort_utils.c\
	   push_swap_sort_numbers.c\
	   push_swap_check.c\
	   push_swap_input.c\
	   get_next_line.c\
	   get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
OBJB = $(addprefix ./bonus/,$(SRCB:%.c=%.o))
LIBFT = ./libft
LIBFT_A = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft
HEADER = push_swap.h
HEADERB = bonus/push_swap.h


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT) bonus

$(NAME): $(OBJS) $(LIBFT_A) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJB) $(LIBFT_A) $(HEADERB)
	$(CC) $(CFLAGS) $(OBJB) $(LIBS) -o checker

clean:
	rm -f $(OBJS)
	rm -f $(OBJB)

fclean: clean
	rm -f $(NAME)
	rm -f checker
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
