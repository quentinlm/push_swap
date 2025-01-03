/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:23:48 by quclaque          #+#    #+#             */
/*   Updated: 2024/10/16 10:23:48 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_size(long n)
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
