NAME = push_swap

FLAGS = -Wall -Werror -Wextra

SRC_PATH = src/

SRC = push_swap.c check_input.c ft_lst.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRCS:.c=.o)

all: $(NAME) libft/libft.a

.c.o :
	cc $(FLAGS) -c $< -o $@ -I ./includes/

libft/libft.a:
	$(MAKE) -C libft

$(NAME): $(OBJ) libft/libft.a
	cc $(CFLAGS) $(OBJ) -o $(NAME) -Llibft -l:libft.a

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all