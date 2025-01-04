/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:33:17 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/04 12:53:12 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	return (new);
}

void	ft_lstadd_front(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	new->next = stack->top;
	if (stack->top)
		stack->top->prev = new;
	new->prev = NULL;
	stack->top = new;
	stack->size++;
}

t_list	*lstlast(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	//redoo with stack->size;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_printlst(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		ft_putendl_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}