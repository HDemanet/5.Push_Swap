/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:06:51 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shifts all elements of stack a down by 1 position, making the last element 
the first. */
void	ft_reverse_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = *stack;
	while ((*stack)->next != temp)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
}

/* Shifts stack a: last element to top, marked '9' in moves[]. */
int	rra(t_list **stack_a, char moves[], int i)
{
	ft_reverse_rotate(stack_a);
	moves[i] = '9';
	i++;
	return (i);
}

/* Shifts stack b: last element to top, marked '3' in moves[]. */
int	rrb(t_list **stack_b, char moves[], int i)
{
	ft_reverse_rotate(stack_b);
	moves[i] = '3';
	i++;
	return (i);
}

/* Shifts stack a and stack b: last elements become first. */
void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
