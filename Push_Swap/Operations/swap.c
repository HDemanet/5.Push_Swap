/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:07:32 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swap operation for the first two elements in a stack. */
void	ft_swap(t_list *stack)
{
	int	temp;

	if (!(stack) || !(stack->next))
		return ;
	temp = (stack->content);
	stack->content = stack->next->content;
	stack->next->content = temp;
}

/* Swap for the first two elements in stack a, recorded as '1' in moves[]. */
int	sa(t_list *stack_a, char moves[], int i)
{
	ft_swap(stack_a);
	moves[i] = '1';
	i++;
	return (i);
}

/* Swap for the first two elements in stack b, recorded as '2' in moves[]. */
int	sb(t_list *stack_b, char moves[], int i)
{
	ft_swap(stack_b);
	moves[i] = '2';
	i++;
	return (i);
}

/* Simultaneously swap the first two elements in both stack a and stack b. */
void	ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
