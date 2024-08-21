/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 16:01:02 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Pushes the top element from one stack (stack-give) to another stack (s-get)*/
void	ft_push(t_list **stack_get, t_list **stack_give)
{
	t_list	*temp;

	if (!(*stack_give))
		return ;
	temp = (*stack_give)->next;
	(*stack_give)->next = *stack_get;
	*stack_get = *stack_give;
	*stack_give = temp;
}

/* Take the 1e element at the top of b and put it at the top of a */
int	pa(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	ft_push(stack_a, stack_b);
	moves[i] = '4';
	i++;
	return (i);
}

/* Take the 1e element at the top of a and put it at the top of b */
int	pb(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	ft_push(stack_b, stack_a);
	moves[i] = '5';
	i++;
	return (i);
}
