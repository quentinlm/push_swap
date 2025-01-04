LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

PRINTF_SRC = ./ft_printf/ft_printf.c ./ft_printf/ft_print_char.c ./ft_printf/ft_format_s.c ./ft_printf/ft_format_p.c ./ft_printf/ft_format_int.c ./ft_printf/ft_format_u.c ./ft_printf/ft_format_x.c ./ft_printf/utils.c

PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

NAME = libft.a

flag = -Wall -Wextra -Werror

all : $(NAME)

.c.o :
	cc $(flag) -c $< -o $@

clean :
	rm -f $(LIBFT_OBJ) $(PRINTF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(LIBFT_OBJ) $(PRINTF_OBJ)
	ar rcs $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)

.PHONY: all clean fclean re
