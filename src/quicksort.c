/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:32:35 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/30 11:37:55 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void move_to_b(t_stack *stack_a, t_stack *stack_b, int value, int flag)
{
    t_list *tmp = stack_a->top;
    int i = 0;
    
    while (tmp && tmp->value != value)
    {
        tmp = tmp->next;
        i++;
    }

    if (!tmp)
		return;

    if (i < stack_a->size / 2)
    {
        while (i-- > 0)
            ra(stack_a);
    }
    else
    {
        i = stack_a->size - i;
        while (i-- > 0)
            rra(stack_a);
    }
    stack_a->top->flag = flag;
    pb(stack_a, stack_b);
}

void	partition_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	t_list	*tmp;
	int		pi;
	int		pivot;

	pi = stack_a->size / 2;
	tmp = stack_a->top;
	while (pi > 0)
	{
		tmp = tmp->next;
		pi--;
	}
	pivot = tmp->value;
	ft_printf("pivot:%d\n", pivot);
	//if pivot is min;
	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->value < pivot)
			move_to_b(stack_a, stack_b, tmp->value, flag);
		tmp = tmp->next;
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	flag;

	flag = 1;
	while (stack_a->size > 2)
	{
		partition_a(stack_a, stack_b, flag);
		flag++;
	}
}
