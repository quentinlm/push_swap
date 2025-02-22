/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:53:00 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 14:33:39 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rot_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = find_place_in_a(stack_a, val);
	if (i < find_index(stack_b, val))
		i = find_index(stack_b, val);
	return (i);
}

int	rot_check_rrarrb_a(t_stack *stack_a, t_stack *s_b, int val)
{
	int	i;

	i = 0;
	if (find_place_in_a(stack_a, val))
		i = lstsize(stack_a) - find_place_in_a(stack_a, val);
	if ((i < (lstsize(s_b) - find_index(s_b, val))) && find_index(s_b, val))
		i = lstsize(s_b) - find_index(s_b, val);
	return (i);
}

int	rot_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = 0;
	if (find_index(stack_b, val))
		i = lstsize(stack_b) - find_index(stack_b, val);
	i = find_place_in_a(stack_a, val) + i;
	return (i);
}

int	rot_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = 0;
	if (find_place_in_a(stack_a, val))
		i = lstsize(stack_a) - find_place_in_a(stack_a, val);
	i = find_index(stack_b, val) + i;
	return (i);
}

int	find_best_ba(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_b;
	i = rot_check_rrarrb_a(stack_a, stack_b, stack_b->value);
	while (tmp)
	{
		if (i > rot_check_rarb_a(stack_a, stack_b, tmp->value))
			i = rot_check_rarb_a(stack_a, stack_b, tmp->value);
		if (i > rot_check_rrarrb_a(stack_a, stack_b, tmp->value))
			i = rot_check_rrarrb_a(stack_a, stack_b, tmp->value);
		if (i > rot_check_rarrb_a(stack_a, stack_b, tmp->value))
			i = rot_check_rarrb_a(stack_a, stack_b, tmp->value);
		if (i > rot_check_rrarb_a(stack_a, stack_b, tmp->value))
			i = rot_check_rrarb_a(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

