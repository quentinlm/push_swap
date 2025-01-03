/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:56:20 by quclaque          #+#    #+#             */
/*   Updated: 2024/11/09 10:15:06 by quclaque         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
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

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	ln;

	ln = n;
	size = ft_int_size(ln);
	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	if (ln == 0)
		res[0] = '0';
	if (ln < 0)
	{
		res[0] = '-';
		ln *= -1;
	}
	size--;
	while (ln > 0)
	{
		res[size--] = (ln % 10) + '0';
		ln /= 10;
	}
	return (res);
}
