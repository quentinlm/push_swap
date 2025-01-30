/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:33:17 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/30 10:32:56 by quclaque         ###   ########.fr       */
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
	new->value = value;
	return (new);
}

void	ft_lstadd_front(t_stack *stack, t_list *new)
{
	if (!stack || !new)
		return ;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

t_list	*lstlast(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
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
	char	*char_tmp;
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		char_tmp = ft_itoa(tmp->value);
		ft_putendl_fd(char_tmp, 1);
		tmp = tmp->next;
		free(char_tmp);
	}
}
