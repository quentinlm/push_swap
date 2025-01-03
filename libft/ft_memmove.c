/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:46:40 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/16 11:06:09 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char		*dtmp;
	const unsigned char	*stmp;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		dtmp = dest + size;
		stmp = src + size;
		while (size-- > 0)
			*--dtmp = *--stmp;
	}
	else if (dest < src)
	{
		dtmp = dest;
		stmp = src;
		while (size-- > 0)
			*dtmp++ = *stmp++;
	}
	return (dest);
}
