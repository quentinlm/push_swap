/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:32:30 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/30 10:34:23 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				flag;
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
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	quicksort(t_stack *stack_a, t_stack *stack_b);

#endif