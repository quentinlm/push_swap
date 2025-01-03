/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:43:50 by qclaqueb          #+#    #+#             */
/*   Updated: 2024/10/17 15:45:32 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t len)
{
	while (len-- && (*first || *second))
		if (*first++ != *second++)
			return ((unsigned char)*(first - 1) - (unsigned char)*(second - 1));
	return (0);
}
