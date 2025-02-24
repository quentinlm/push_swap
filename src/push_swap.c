/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:12 by quclaque          #+#    #+#             */
/*   Updated: 2025/02/24 08:12:02 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

void	ft_error(void)
{
	write (2, "Erroreeeee\n", 6);
	exit(1);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}


t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i]);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

/* int	fill_stack_a(t_stack **stack_a, char **av, int ac)
{
	t_stack	*new_node;

	while (ac > 1)
	{
		new_node = ft_lstnew(ft_atoi(av[ac - 1]));
		if (!new_node)
			return (-1);
		new_node->next = *stack_a;
		*stack_a = new_node;
		ac--;
	}
	return (0);
} */

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (-1);
	stack_a = ft_process(ac, av);
	//if (!check_input(av))
	//	return (-1);
	//stack_a = NULL;
	stack_b = NULL;
	//fill_stack_a(&stack_a, av, ac);

	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
		
	ft_printf("Before:\n");
	ft_printlst(stack_a);

	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);

	ft_printf("After:\n");
	ft_printlst(stack_a);

	free_lst(stack_a, stack_b);
	return (0);
}
