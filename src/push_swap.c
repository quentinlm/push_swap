/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:12 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 12:37:35 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fill_stack_a(t_stack **stack_a, char **av, int ac)
{
	t_stack	*new_node;

	while (ac > 1)
	{
		new_node = ft_lstnew(ft_atoi(av[ac - 1]));
		if (!new_node)
			return (-1);
		new_node->next = *stack_a;
		*stack_a = new_node;
		ac--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (-1);
	if (!check_input(av))
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	fill_stack_a(&stack_a, av, ac);
	free_lst(stack_a, stack_b);
	return (0);
}
