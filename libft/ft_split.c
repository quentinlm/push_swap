/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:21:03 by quclaque          #+#    #+#             */
/*   Updated: 2024/10/16 10:21:03 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
		{
			trigger = 0;
		}
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	if (start >= finish)
		return (NULL);
	word = malloc((finish - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j - 1)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_split_sub(size_t i, char c, const char *s, char **split)
{
	size_t	j;
	int		index;

	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (!split[j - 1])
			{
				ft_free_split(split, j);
				return (0);
			}
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_split_sub(i, c, s, split))
		return (NULL);
	return (split);
}
