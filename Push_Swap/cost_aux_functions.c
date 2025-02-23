/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_aux_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/09 16:45:27 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates and returns the average value of the elements in the stack. */
int	ft_get_dynamic_average(t_list *stack_a)
{
	long long	sum;
	int			average;
	int			size;

	sum = 0;
	size = ft_lstsize(stack_a);
	while (stack_a)
	{
		sum += stack_a->content;
		stack_a = stack_a->next;
	}
	average = sum / size;
	return (average);
}

/* Rotates the stack so that the max element is moved to the last position, 
recording the movements. */
int	ft_rotate_until_last_is_last(t_list **stack_a, char moves[], int i)
{
	int	max;
	int	index;
	int	nb_rotations;

	max = ft_get_max(*stack_a);
	index = ft_get_index(max, *stack_a) + 1;
	nb_rotations = ft_lstsize(*stack_a) - index;
	if (index < nb_rotations)
	{
		while (index--)
		{
			ra(stack_a, moves, i);
			i++;
		}
	}
	else
	{
		while (nb_rotations--)
		{
			rra(stack_a, moves, i);
			i++;
		}
	}
	return (i);
}
