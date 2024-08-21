/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 16:00:16 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Counts the tot nbr of individual nbrs in the given command-line arguments. */
int	ft_count_numbers(char **av)
{
	int		i;
	int		j;
	char	**list_str;
	int		nb;

	nb = 0;
	i = 0;
	while (av[++i])
	{
		list_str = ft_split(av[i], ' ');
		j = -1;
		while (list_str[++j])
		{
			nb++;
			free(list_str[j]);
		}
		free(list_str);
	}
	return (nb);
}

/* Loads a linked list stack with numbers parsed from the given command-line 
arguments, performing validation and duplication checks. */
t_list	*ft_load_stack_from_args(char **av)
{
	int		i;
	int		j;
	char	**list_str;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (av[++i])
	{
		list_str = ft_split(av[i], ' ');
		j = -1;
		while (list_str[++j])
		{
			if (!ft_check_nb(list_str[j]))
				return (ft_free_all(list_str, stack_a, j));
			if (!ft_check_double(stack_a, ft_atoi(list_str[j])))
				return (ft_free_all(list_str, stack_a, j));
			ft_lstadd_back(&stack_a, ft_lstnew((int)ft_atoi(list_str[j])));
			free(list_str[j]);
		}
		free(list_str);
	}
	return (stack_a);
}
