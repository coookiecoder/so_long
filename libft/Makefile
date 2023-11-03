files = isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd

sources = $(foreach buffer, $(files), ft_$(buffer).c)

objects = $(foreach buffer, $(files), ft_$(buffer).o)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(objects)
	ar -rc $(NAME) $(objects)

clean:
	rm -rf $(objects)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: all
	$(CC) $(CFLAGS) main.c $(NAME) -o OUTPUT -g3 -fsanitize=address

.PHONY: all clean fclean re debug
