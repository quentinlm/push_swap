/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:42:02 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/24 08:15:28 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	sort_for_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = find_best_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == rot_check_rarb(*stack_a, *stack_b, tmp->value))
				i = set_rarb_a(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rrarrb(*stack_a, *stack_b, tmp->value))
				i = set_rrarrb_a(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rarrb(*stack_a, *stack_b, tmp->value))
				i = set_rarrb_a(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rrarb(*stack_a, *stack_b, tmp->value))
				i = set_rrarb_a(stack_a, stack_b, tmp->value);
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_for_three(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (*stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = find_best_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == rot_check_rarb_a(*stack_a, *stack_b, tmp->value))
				i = set_rarb_b(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rarrb_a(*stack_a, *stack_b, tmp->value))
				i = set_rarrb_b(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rrarrb_a(*stack_a, *stack_b, tmp->value))
				i = set_rrarrb_b(stack_a, stack_b, tmp->value);
			else if (i == rot_check_rrarb_a(*stack_a, *stack_b, tmp->value))
				i = set_rrarb_b(stack_a, stack_b, tmp->value);
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	if (lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		*stack_b = sort_b(stack_a, stack_b);
		*stack_a = *sort_a(stack_a, stack_b);
		i = find_index(*stack_a, ft_min(*stack_a));
		if (i < lstsize(*stack_a) - i)
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
} */

static int	apply_rotation(t_stack **a, t_stack **b, int value, char stack)
{
	int	i;

	if (stack == 'a')
	{
		if ((i = rot_check_rarb(*a, *b, value)) >= 0)
			return (set_rarb_a(a, b, value));
		if ((i = rot_check_rrarrb(*a, *b, value)) >= 0)
			return (set_rrarrb_a(a, b, value));
		if ((i = rot_check_rarrb(*a, *b, value)) >= 0)
			return (set_rarrb_a(a, b, value));
		if ((i = rot_check_rrarb(*a, *b, value)) >= 0)
			return (set_rrarb_a(a, b, value));
	}
	else
	{
		if ((i = rot_check_rarb_a(*a, *b, value)) >= 0)
			return (set_rarb_b(a, b, value));
		if ((i = rot_check_rrarrb_a(*a, *b, value)) >= 0)
			return (set_rrarrb_b(a, b, value));
		if ((i = rot_check_rarrb_a(*a, *b, value)) >= 0)
			return (set_rarrb_b(a, b, value));
		if ((i = rot_check_rrarb_a(*a, *b, value)) >= 0)
			return (set_rrarb_b(a, b, value));
	}
	return (-1);
}

void	reduce_to_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		rot_count;

	while (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		rot_count = find_best_ab(*stack_a, *stack_b);
		while (rot_count >= 0)
		{
			rot_count = apply_rotation(stack_a, stack_b, tmp->value, 'a');
			if (rot_count < 0)
				tmp = tmp->next;
		}
	}
}

t_stack	*prepare_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	reduce_to_three(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (*stack_b);
}

void	merge_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		rot_count;

	while (*stack_b)
	{
		tmp = *stack_b;
		rot_count = find_best_ba(*stack_a, *stack_b);
		while (rot_count >= 0)
		{
			rot_count = apply_rotation(stack_a, stack_b, tmp->value, 'b');
			if (rot_count < 0)
				tmp = tmp->next;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int		min_idx;
	int		size;

	if (!stack_a || !*stack_a)
		return ;
	if (lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		*stack_b = prepare_stack_b(stack_a, stack_b);
		merge_stack_a(stack_a, stack_b);
		min_idx = find_index(*stack_a, ft_min(*stack_a));
		size = lstsize(*stack_a);
		while ((*stack_a)->value != ft_min(*stack_a))
		{
			if (min_idx < size - min_idx)
				ra(stack_a);
			else
				rra(stack_a);
		}
	}
}
