/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_poss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:59:51 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 13:06:52 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(t_stack *stack_a, int value)
{
	int	i;

	i = 0;
	while (stack_a->value != value)
	{
		i++;
		stack_a = stack_a->next;
	}
	stack_a->index = 0;
	return (i);
}

int	find_place_in_b(t_stack *stack_b, int check_val)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (check_val > stack_b->value && check_val < ft_lstlast(stack_b)->value)
		i = 0;
	else if (check_val > ft_max(stack_b) || check_val < ft_min(stack_b))
		i = find_index;
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < check_val || tmp->value > check_val)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_in_a(t_stack *stack_a, int check_val)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (check_val < stack_a->value && check_val > ft_lstlast(stack_a)->value)
		i = 0;
	else if (check_val > ft_max(stack_a) || check_val < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > check_val || tmp->value < check_val)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
