/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:10:10 by quclaque          #+#    #+#             */
/*   Updated: 2024/10/17 16:10:10 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tp;

	while (*lst)
	{
		tp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tp;
	}
	*lst = 0;
}
