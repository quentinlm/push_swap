/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:47:09 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 12:55:04 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(t_stack *stack)
{
	int		i;

	i = stack->value;
	while (stack)
	{
		if (stack->value < i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	ft_max(t_stack *stack)
{
	int		i;

	i = stack->value;
	while (stack->value)
	{
		if (stack->value > i)
			i = stack->value;
		stack = stack->value;
	}
	return (i);
}

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->value;
	while (stack_a)
	{
		if (i > stack_a->value)
			return (0);
		i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}