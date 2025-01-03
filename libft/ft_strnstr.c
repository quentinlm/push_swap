/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:44:11 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/16 10:04:20 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fullstr, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (substr[0] == '\0')
		return ((char *)fullstr);
	while (fullstr[i] && i + j < len)
	{
		if (fullstr[i + j] == substr[j])
		{
			if (substr[++j] == '\0')
				return ((char *)fullstr + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}
