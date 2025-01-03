/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:50:30 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/17 13:13:03 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dtmp;
	const unsigned char	*stmp;

	if (!dest && !src)
		return (0);
	dtmp = dest;
	stmp = src;
	while (size-- > 0)
	{
		*dtmp++ = *stmp++;
	}
	return (dest);
}
