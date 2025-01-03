/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:15:31 by quclaque          #+#    #+#             */
/*   Updated: 2024/11/08 07:46:35 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(size_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_put_nbr(size_t n, int flag)
{
	char	buffer[16];
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (n > 0)
	{
		if (flag == 1)
			buffer[i++] = "0123456789ABCDEF"[n % 16];
		else if (flag == 0)
			buffer[i++] = "0123456789abcdef"[n % 16];
		len++;
		n /= 16;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (len);
}

int	ft_format_x(va_list args, int flag)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(args, unsigned int);
	len = ft_ptr_len(nbr);
	if (nbr == 0)
		return (write(1, "0", 1));
	else if (len > 0)
		return (ft_put_nbr(nbr, flag));
	return (0);
}
