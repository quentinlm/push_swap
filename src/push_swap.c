/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:12 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/30 10:55:45 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		value;

	if (stack->size == 0)
		return (-1);
	tmp = stack->top;
	value = tmp->value;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (value);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	fill_stack_a(t_stack *stack_a, char **av, int ac)
{
	ac -= 1;
	while (ac > 0)
	{
		push(stack_a, ft_atoi(av[ac]));
		ac--;
	}
}

void	free_lst(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*current;
	t_list	*tmp;

	current = stack_a->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack_a);
	current = stack_b->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (-1);
	if (!check_input(av))
		return (-1);
	stack_a = init_stack();
	stack_b = init_stack();
	fill_stack_a(stack_a, av, ac);
	ft_printf("Before---\n");
	ft_printlst(stack_a);
	quicksort(stack_a, stack_b);
	ft_printf("After---\n");
	ft_printlst(stack_a);
	free_lst(stack_a, stack_b);
	return (0);
}
