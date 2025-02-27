/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:18:03 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/27 14:44:33 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rot_check_rarb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	idx_a;

	cost = find_place_in_b(stack_b, val);
	idx_a = find_index(stack_a, val);
	if (cost < idx_a)
		cost = idx_a;
	return (cost);
}

int	rot_check_rrarrb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	idx_a;
	int	size_a;
	int	place_b;

	cost = 0;
	idx_a = find_index(stack_a, val);
	size_a = lstsize(stack_a);
	place_b = find_place_in_b(stack_b, val);
	if (place_b)
		cost = lstsize(stack_b) - place_b;
	if (cost < (size_a - idx_a))
		cost = size_a - idx_a;
	return (cost);
}

int	rot_check_rrarb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	idx_a;

	cost = 0;
	idx_a = find_index(stack_a, val);
	if (idx_a)
		cost = lstsize(stack_a) - idx_a;
	cost = find_place_in_b(stack_b, val) + cost;
	return (cost);
}

int	rot_check_rarrb(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	cost;
	int	place_b;

	cost = 0;
	place_b = find_place_in_b(stack_b, val);
	if (place_b)
		cost = lstsize(stack_b) - place_b;
	cost = find_index(stack_a, val) + cost;
	return (cost);
}

int	find_best_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		best_cost;
	int		current_cost;

	current = stack_a;
	best_cost = rot_check_rrarrb(stack_a, stack_b, stack_a->value);
	while (current)
	{
		current_cost = rot_check_rarb(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rrarrb(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rrarb(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current_cost = rot_check_rarrb(stack_a, stack_b, current->value);
		if (current_cost < best_cost)
			best_cost = current_cost;
		current = current->next;
	}
	return (best_cost);
}
