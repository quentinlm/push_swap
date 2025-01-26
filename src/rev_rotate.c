/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:55:16 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 13:13:36 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;

	tmp = stack->top;
	last = lstlast(stack);

	stack->top = last->prev;
	stack->top->next = NULL;

	last->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	stack->top = last;
}

void	rra(t_stack *stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
