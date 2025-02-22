/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:33:17 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/22 12:46:28 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_lst(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack_a;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	current = stack_b;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_printlst(t_stack *stack)
{
	char	*char_tmp;
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		char_tmp = ft_itoa(tmp->value);
		ft_putendl_fd(char_tmp, 1);
		tmp = tmp->next;
		free(char_tmp);
	}
}
