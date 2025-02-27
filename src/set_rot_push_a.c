/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rot_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:38:50 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/27 16:43:08 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* int	set_rarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val && find_place_in_b(*stack_b, val) > 0)
		rr(stack_a, stack_b);
	while ((*stack_a)->value != val)
		ra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rb(stack_b);
	pb(stack_a, stack_b);
	return (-1);
}

int	set_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val && find_place_in_b(*stack_b, val) > 0)
		rrr(stack_a, stack_b);
	while ((*stack_a)->value != val)
		rra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rrb(stack_b);
	pb(stack_a, stack_b);
	return (-1);
}

int	set_rrarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val)
		rra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rb(stack_b);
	pb(stack_a, stack_b);
	return (-1);
}

int	set_rarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
	while ((*stack_a)->value != val)
		ra(stack_a);
	while (find_place_in_b(*stack_b, val) > 0)
		rrb(stack_b);
	pb(stack_a, stack_b);
	return (-1);
} */

static void rotate_a_forward_until_val(t_stack **stack_a, int val)
{
    while ((*stack_a)->value != val)
        ra(stack_a);
}

static void rotate_a_backward_until_val(t_stack **stack_a, int val)
{
    while ((*stack_a)->value != val)
        rra(stack_a);
}

static void rotate_both_forward_while(t_stack **stack_a, t_stack **stack_b, int val)
{
    // Assumes we want forward rotation if stack_a != val and place_in_b > 0
    while ((*stack_a)->value != val && find_place_in_b(*stack_b, val) > 0)
        rr(stack_a, stack_b);
}

static void rotate_both_backward_while(t_stack **stack_a, t_stack **stack_b, int val)
{
    // Assumes backward rotation if stack_a != val and place_in_b > 0
    while ((*stack_a)->value != val && find_place_in_b(*stack_b, val) > 0)
        rrr(stack_a, stack_b);
}

// ------------------------------------
//  Functions for pushing from stack A
// ------------------------------------

int set_rarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
    // Rotate both forward while needed, then A alone, then B alone, then pb
    rotate_both_forward_while(stack_a, stack_b, val);
    rotate_a_forward_until_val(stack_a, val);
    while (find_place_in_b(*stack_b, val) > 0)
        rb(stack_b);
    pb(stack_a, stack_b);
    return (-1);
}

int set_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
    // Rotate both backward while needed, then A alone, then B alone, then pb
    rotate_both_backward_while(stack_a, stack_b, val);
    rotate_a_backward_until_val(stack_a, val);
    while (find_place_in_b(*stack_b, val) > 0)
        rrb(stack_b);
    pb(stack_a, stack_b);
    return (-1);
}

int set_rrarb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
    // A backward, then B forward, then pb
    rotate_a_backward_until_val(stack_a, val);
    while (find_place_in_b(*stack_b, val) > 0)
        rb(stack_b);
    pb(stack_a, stack_b);
    return (-1);
}

int set_rarrb_a(t_stack **stack_a, t_stack **stack_b, int val)
{
    // A forward, then B backward, then pb
    rotate_a_forward_until_val(stack_a, val);
    while (find_place_in_b(*stack_b, val) > 0)
        rrb(stack_b);
    pb(stack_a, stack_b);
    return (-1);
}
