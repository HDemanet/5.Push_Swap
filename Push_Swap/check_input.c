/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:31:31 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* max : 2147483647 ; min : -2147483648 */
/* Checks if a given string represents a number within the int range limits. */
int	ft_check_limits(char *str)
{
	int			i;
	long long	num;
	int			sign;

	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	num = 0;
	i--;
	while (str[++i])
		num = num * 10 + str[i] - '0';
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		return (0);
	return (1);
}

/* Verifies if a string is a valid number and within the int range. */
int	ft_check_nb(char *str_nb)
{
	int	i;

	i = -1;
	if (str_nb[0] == '-' || str_nb[0] == '+')
		i++;
	if (str_nb[0] == '-' && str_nb[1] == 0)
		return (0);
	while (str_nb[++i])
	{
		if (!ft_isdigit(str_nb[i]))
			return (0);
	}
	if (!ft_check_limits(str_nb))
		return (0);
	return (1);
}

/* Checks for duplicate values in a linked list. */
int	ft_check_double(t_list *stack_a, int a)
{
	while (stack_a)
	{
		if (stack_a->content == a)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* Frees all memory allocated for a linked list. */
void	ft_free_stack(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}

/* Frees memory for both a string array and a linked list. */
t_list	*ft_free_all(char **list_str, t_list *stack_a, int i)
{
	i--;
	while (list_str[++i])
		free(list_str[i]);
	free(list_str);
	ft_free_stack(stack_a);
	return (NULL);
}
