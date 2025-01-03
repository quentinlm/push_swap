/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:50:12 by quclaque          #+#    #+#             */
/*   Updated: 2024/11/10 09:40:24 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char format)
{
	if (format == 'c')
		return (0);
	else if (format == 's')
		return (0);
	else if (format == 'p')
		return (0);
	else if (format == 'd' || format == 'i')
		return (0);
	else if (format == 'u')
		return (0);
	else if (format == 'x')
		return (0);
	else if (format == 'X')
		return (0);
	else if (format == '%')
		return (0);
	return (1);
}

int	formating(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(args));
	else if (format == 's')
		return (ft_format_s(args));
	else if (format == 'p')
		return (ft_format_p(args));
	else if (format == 'd' || format == 'i')
		return (ft_format_int(args));
	else if (format == 'u')
		return (ft_format_u(args));
	else if (format == 'x')
		return (ft_format_x(args, 0));
	else if (format == 'X')
		return (ft_format_x(args, 1));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	if (!format)
		return (-1);
	ret = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && check_format(format[i + 1]) != 0)
			return (-1);
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ret += formating(args, format[i + 1]);
			i++;
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}
