/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:00 by quclaque          #+#    #+#             */
/*   Updated: 2024/11/08 07:46:33 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_num_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_format_u(va_list args)
{
	unsigned int	nbr;
	char			*str;
	size_t			len;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_u(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
