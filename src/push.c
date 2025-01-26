/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:39:11 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 12:12:32 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_list	*tmp;

	if (!from->top)
		return ;

	tmp = from->top;
	from->top = from->top->next;
	if (from->top)
		from->top->prev = NULL;
	tmp->next = to->top;
	if (to->top)
		to->top->prev = tmp;
	to->top = tmp;
	to->top->prev = NULL;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
