/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:32:14 by quclaque          #+#    #+#             */
/*   Updated: 2024/11/08 07:46:29 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(size_t nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_put_nbr(unsigned long long n)
{
	char	buffer[16];
	int		i;

	i = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		buffer[i++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
	}
}

int	ft_format_p(va_list args)
{
	size_t	nbr;

	nbr = va_arg(args, unsigned long long);
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		ft_put_nbr(nbr);
		return (ft_ptr_len(nbr) + 2);
	}
}
