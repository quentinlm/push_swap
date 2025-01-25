/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:50:45 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/25 13:06:20 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] && is_sign(av[i]))
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	check_doubles(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strncmp(av[i], av[j], ft_strlen(av[i]) == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (!check_doubles(av))
		return (0);
	return (1);
}
