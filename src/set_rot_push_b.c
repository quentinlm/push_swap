/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:09:26 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 14:28:33 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_rarb_b(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_b)->value != val && find_place_in_a(*stack_a, val) > 0)
		rr(stack_a, stack_b);
	while ((*stack_b)->value != val)
		rb(stack_b);
	while (find_place_in_a(*stack_a, val) > 0)
		ra(stack_a);
	pa(stack_a, stack_b);
	return (-1);
}

int	set_rrarrb_b(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_b)->value != val && find_place_in_a(*stack_a, val) > 0)
		rrr(stack_a, stack_b);
	while ((*stack_b)->value != val)
		rrb(stack_b);
	while (find_place_in_a(*stack_a, val) > 0)
		rra(stack_a);
	pa(stack_a, stack_b);
	return (-1);
}

int	set_rrarb_b(t_stack **stack_a, t_stack **stack_b, int val)
{
	while (find_place_in_a(*stack_a, val) > 0)
		rra(stack_a);
	while ((*stack_b)->value != val)
		rb(stack_b);
	pa(stack_a, stack_b);
	return (-1);
}

int	set_rarrb_b(t_stack **stack_a, t_stack **stack_b, int val)
{
	while (find_place_in_a(*stack_a, val))
		ra(stack_a);
	while ((*stack_b)->value != val)
		rrb(stack_b);
	pa(stack_a, stack_b);
	return (-1);
}
