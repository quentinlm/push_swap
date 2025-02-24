/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:18:03 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/24 10:47:39 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rot_check_rarb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = find_place_in_b(stack_b, val);
	if (i < find_index(stack_a, val))
		i = find_index(stack_a, val);
	return (i);
}

int	rot_check_rrarrb(t_stack *s_a, t_stack *stack_b, int val)
{
	int	i;

	i = 0;
	if (find_place_in_b(stack_b, val))
		i = lstsize(stack_b) - find_place_in_b(stack_b, val);
	if (i < lstsize(s_a) - find_index(s_a, val) && find_index(s_a, val))
		i = lstsize(s_a) - find_index(s_a, val);
	return (i);
}

int	rot_check_rrarb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = 0;
	if (find_index(stack_a, val))
		i = lstsize(stack_a) - find_index(stack_a, val);
	i = find_place_in_b(stack_b, val) + i;
	return (i);
}

int	rot_check_rarrb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	i;

	i = 0;
	if (find_place_in_b(stack_b, val))
		i = lstsize(stack_b) - find_place_in_b(stack_b, val);
	i = find_index(stack_a, val) + i;
	return (i);
}

int	find_best_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = rot_check_rrarrb(stack_a, stack_b, stack_a->value);
	while (tmp)
	{
		if (i > rot_check_rarb(stack_a, stack_b, tmp->value))
			i = rot_check_rarb(stack_a, stack_b, tmp->value);
		if (i > rot_check_rrarrb(stack_a, stack_b, tmp->value))
			i = rot_check_rrarrb(stack_a, stack_b, tmp->value);
		if (i > rot_check_rrarb(stack_a, stack_b, tmp->value))
			i = rot_check_rrarb(stack_a, stack_b, tmp->value);
		if (i > rot_check_rarrb(stack_a, stack_b, tmp->value))
			i = rot_check_rarrb(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
