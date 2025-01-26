/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:56:20 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 11:25:08 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

int	ft_isdigite(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlene(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++ != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_int_size(long n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}
