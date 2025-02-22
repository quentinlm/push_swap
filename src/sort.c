/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:42:02 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 13:37:36 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_for_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (lstsize(*stack_a) > 3 && is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = find_best_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == rot_check_rarb(*stack_a, *stack_b, tmp->value))
				i = set_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == rot_check_rrarrb(*stack_a, *stack_b, tmp->value))
				i = set_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == rot_check_rarrb(*stack_a, *stack_b, tmp->value))
				i = set_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == rot_check_rrarb(*stack_a, *stack_b, tmp->value))
				i = set_rrarb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_for_three(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack;
	int		i;

	if (lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = sort_b(stack_a, stack_b);
		stack_a = sort_a(stack, &stack_b);
		i = find_index(*stack_a, ft_min(*stack_a));
		if (i < listsize(*stack_a) - i)
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				rra(stack_a);
		}
	}
}