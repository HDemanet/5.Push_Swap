/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/10 09:19:38 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves an element in stack A to the top using rotations based on its index.*/
int	ft_put_top_a(t_list **lst, int index, char moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = ra(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rra(lst, moves, j);
			i++;
		}
	}
	return (j);
}

/* Moves an element in stack B to the top using rotations based on its index.*/
int	ft_put_top_b(t_list **lst, int index, char moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = rb(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rrb(lst, moves, j);
			i++;
		}
	}
	return (j);
}
