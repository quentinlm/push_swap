/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:37:49 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/16 09:55:37 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*p1tmp;
	const unsigned char	*p2tmp;

	p1tmp = (const unsigned char *)p1;
	p2tmp = (const unsigned char *)p2;
	while (size-- > 0)
	{
		if (*p1tmp != *p2tmp)
			return (*p1tmp - *p2tmp);
		p1tmp++;
		p2tmp++;
	}
	return (0);
}
