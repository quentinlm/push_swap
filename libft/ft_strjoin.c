/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:12:57 by quclaque          #+#    #+#             */
/*   Updated: 2024/10/16 10:12:57 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*strjoin;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!strjoin)
		return (0);
	strjoin[s1_len + s2_len] = '\0';
	i = 0;
	while (*s1)
		strjoin[i++] = *s1++;
	while (*s2)
		strjoin[i++] = *s2++;
	return (strjoin);
}
