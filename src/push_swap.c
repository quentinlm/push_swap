/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:12 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 12:11:25 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	new_node->next = stack->top;
	if (stack->top)
		stack->top->prev = new_node;
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
	if (stack->top)
		stack->top->prev = NULL;
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (-1);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!check_input(av))
		return (-1);
	fill_stack_a(stack_a, av, ac);
	ft_printlst(stack_a);
	sa(stack_a);
	ft_printlst(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_printlst(stack_a);
	ft_printf("--\n");
	ft_printlst(stack_b);
}
