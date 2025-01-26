/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:32:30 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 11:36:31 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}				t_stack;

t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack *stack, t_list *new);
t_list	*lstlast(t_stack *stack);
void	ft_printlst(t_stack *stack);
int		check_input(char **av);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);

#endif