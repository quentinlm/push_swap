/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:32:21 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/25 12:54:45 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, str, ft_strlene(str)));
}
