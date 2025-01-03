/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:13:56 by quclaque          #+#    #+#             */
/*   Updated: 2024/10/16 10:13:56 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	shrchar(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	len;

	while (*s1 && shrchar(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && shrchar(s1[len - 1], set))
		len--;
	tab = (char *)malloc(len + 1 * sizeof(char));
	if (!tab)
		return (0);
	ft_memcpy(tab, s1, len);
	tab[len] = '\0';
	return (tab);
}
