/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:05:03 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks for white space characters in a string. */
const char	*ft_white_spaces(const char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

/* Converts a decimal integer string to an integer. */
int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	str = ft_white_spaces(str);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
