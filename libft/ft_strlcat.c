/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:42:09 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/17 14:54:49 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destsize;

	i = 0;
	destsize = ft_strlen(dst);
	if (size <= destsize)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && (destsize + i + 1) < size)
	{
		dst[destsize + i] = src[i];
		i++;
	}
	dst[destsize + i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
