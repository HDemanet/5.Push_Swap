/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:06:13 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Returns the maximum content value of the linked list. */
int	ft_get_max(t_list *lst)
{
	int	i;
	int	max;

	if (!lst)
		return (-1);
	i = 0;
	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

/* Returns the minimum content value of the linked list. */
int	ft_get_min(t_list *lst)
{
	int	i;
	int	min;

	if (!lst)
		return (-1);
	i = 0;
	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

/* Returns the index of the element in the linked list that matches 
the given content value. */
int	ft_get_index(int nb, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

/* Returns the size of the linked list. */
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
