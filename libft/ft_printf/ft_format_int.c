/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:33:00 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/25 12:55:06 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_int(va_list args)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	len = ft_strlene(str);
	write(1, &str[0], len);
	free(str);
	return (len);
}
