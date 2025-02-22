/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:38:50 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 13:49:27 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_rarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val && find_place_in_a(*stack_b, val) > 0)
		rr(stack_a, stack_b);
	while ((*stack_a)->value != val)
		ra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rb(stack_b);
	pb(&stack_a, stack_b);
}

int	set_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val && find_place_in_b(*stack_b, val) > 0)
		rrr(stack_a, stack_b);
	while ((*stack_a)->value != val)
		rra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rrb(stack_b);
	pb(&stack_a, stack_b);
}

int	set_rrarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val)
		rra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rb(stack_b);
	pb(&stack_a, stack_b);
}

int	set_rarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val)
		ra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rrb(stack_b);
	pb(&stack_a, stack_b);
}
