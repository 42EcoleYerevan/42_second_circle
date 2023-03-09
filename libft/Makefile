NAME = libft.a

MODULES = ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_strlen.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_strlcpy.o \
		ft_strlcat.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strncmp.o \
		ft_memchr.o \
		ft_strnstr.o \
		ft_memcmp.o \
		ft_atoi.o \
		ft_calloc.o \
		ft_strdup.o \
		ft_substr.o \
		ft_strjoin.o \
		ft_strtrim.o \
		ft_split.o \
		ft_itoa.o \
		ft_strmapi.o \
		ft_striteri.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o 

BONUS = ft_lstnew.o \
		ft_lstadd_front.o \
		ft_lstsize.o \
		ft_lstlast.o \
		ft_lstadd_back.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstclear.o \
		ft_lstmap.o \
		$(MODULES)

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MODULES) $(HEADER)
	ar r $(NAME) $(MODULES)

all: $(NAME)

clean:
	rm -rf $(BONUS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

bonus: $(BONUS)
	ar r $(NAME) $(BONUS)

.PHONY: all clean fclean re bonus
