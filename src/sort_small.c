/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:42:05 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 13:12:17 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->value)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)->value)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (find_index(*stack_a, ft_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}
