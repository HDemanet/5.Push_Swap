/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 16:01:18 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift up all elements of stack a by 1. The 1e element becomes the last one.*/
void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

/* Shifts stack a: first element to last, marked '6' in moves[]. */
int	ra(t_list **stack_a, char moves[], int i)
{
	ft_rotate(stack_a);
	moves[i] = '6';
	i++;
	return (i);
}

/* Shifts stack b: first element to last, marked '7' in moves[]. */
int	rb(t_list **stack_b, char moves[], int i)
{
	ft_rotate(stack_b);
	moves[i] = '7';
	i++;
	return (i);
}

/* Shifts stack a and stack b: first elements to last. */
void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
