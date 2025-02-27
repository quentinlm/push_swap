/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:32:30 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/26 14:00:15 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstlast(t_stack *stack);
t_stack	*ft_lstnew(int value);
void	ft_printlst(t_stack *stack);
void	free_lst(t_stack *stack_a, t_stack *stack_b);
int		check_input(char **av);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		lstsize(t_stack *lst);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
int		is_sorted(t_stack *stack_a);
int		find_index(t_stack *stack_a, int value);
int		find_place_in_b(t_stack *stack_b, int check_val);
int		find_place_in_a(t_stack *stack_a, int check_val);
void	sort_three(t_stack **stack_a);
int		find_best_ab(t_stack *stack_a, t_stack *stack_b);
int		rot_check_rarb(t_stack *stack_a, t_stack *stack_b, int val);
int		rot_check_rrarrb(t_stack *s_a, t_stack *stack_b, int val);
int		rot_check_rrarb(t_stack *stack_a, t_stack *stack_b, int val);
int		rot_check_rarrb(t_stack *stack_a, t_stack *stack_b, int val);
int		set_rarb_a(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rrarb_a(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rarrb_a(t_stack **stack_a, t_stack **stack_b, int val);
int		find_best_ba(t_stack *stack_a, t_stack *stack_b);
int		rot_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int val);
int		rot_check_rrarrb_a(t_stack *stack_a, t_stack *s_b, int val);
int		rot_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int val);
int		rot_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int val);
int		set_rarb_b(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rrarrb_b(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rrarb_b(t_stack **stack_a, t_stack **stack_b, int val);
int		set_rarrb_b(t_stack **stack_a, t_stack **stack_b, int val);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif
