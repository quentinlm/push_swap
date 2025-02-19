/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:32:35 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/18 09:22:19 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	partition_a(t_stack *stack_a, t_stack *stack_b, int flag)
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
}*/

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	
}
