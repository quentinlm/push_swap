NAME = push_swap

FLAGS = -Wall -Werror -Wextra -g

SRC_PATH = src/

SRC = push_swap.c check_input.c ft_lst.c swap.c push.c rotate.c rev_rotate.c \
		ft_util.c set_rot_push_a.c set_rot_push_b.c sort_opti_ab.c sort_opti_ba.c \
		sort_small.c sort.c stack_poss.c

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
	$(MAKE) clean -C libft

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all