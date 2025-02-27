/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:53:00 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/27 14:44:50 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rot_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	idx_b;

	cost = find_place_in_a(stack_a, val);
	idx_b = find_index(stack_b, val);
	if (cost < idx_b)
		cost = idx_b;
	return (cost);
}

int	rot_check_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	size_b;
	int	idx_b;

	cost = 0;
	size_b = lstsize(stack_b);
	idx_b = find_index(stack_b, val);
	if (find_place_in_a(stack_a, val))
		cost = lstsize(stack_a) - find_place_in_a(stack_a, val);
	if (cost < (size_b - idx_b))
		cost = size_b - idx_b;
	return (cost);
}

int	rot_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	idx_b;

	cost = 0;
	idx_b = find_index(stack_b, val);
	if (idx_b)
		cost = lstsize(stack_b) - idx_b;
	cost = find_place_in_a(stack_a, val) + cost;
	return (cost);
}

int	rot_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	place_a;

	cost = 0;
	place_a = find_place_in_a(stack_a, val);
	if (place_a)
		cost = lstsize(stack_a) - place_a;
	cost = find_index(stack_b, val) + cost;
	return (cost);
}

int	find_best_ba(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		best_cost;
	int		current_cost;

	if (!stack_b)
		return (0);
	current = stack_b;
	best_cost = rot_check_rrarrb_a(stack_a, stack_b, current->value);
	while (current)
	{
		current_cost = rot_check_rarb_a(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rrarrb_a(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rarrb_a(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rrarb_a(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current = current->next;
	}
	return (best_cost);
}
