/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 14:47:08 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Writes a specific command to standard output based on the char at index 'j' 
in the moves array. */
void	ft_normal_moves(char moves[], int j)
{
	if (moves[j] == '1')
		write(1, "sa\n", 3);
	else if (moves[j] == '2')
		write(1, "sb\n", 3);
	else if (moves[j] == '4')
		write(1, "pa\n", 3);
	else if (moves[j] == '5')
		write(1, "pb\n", 3);
	else if (moves[j] == '6')
		write(1, "ra\n", 3);
	else if (moves[j] == '7')
		write(1, "rb\n", 3);
	else if (moves[j] == '9')
		write(1, "rra\n", 4);
	else if (moves[j] == '3')
		write(1, "rrb\n", 4);
}

/* Writes an optimized command if possible. */
int	ft_better_moves(char moves[], int j)
{
	if ((moves[j] == '1' && moves[j + 1] == '2') \
	|| (moves[j] == '2' && moves[j + 1] == '1'))
	{
		write(1, "ss\n", 3);
		j++;
	}
	else if ((moves[j] == '6' && moves[j + 1] == '7') \
	|| (moves[j] == '7' && moves[j + 1] == '6'))
	{
		write(1, "rr\n", 3);
		j++;
	}
	else if ((moves[j] == '9' && moves[j + 1] == '3') \
	|| (moves[j] == '3' && moves[j + 1] == '9'))
	{
		write(1, "rrr\n", 4);
		j++;
	}
	return (j);
}

/* Writes commands from the moves array. */
void	ft_print_moves(char moves[], int i)
{
	int	j;
	int	tmp;

	j = 0;
	while (j <= i)
	{
		tmp = j;
		j = ft_better_moves(moves, j);
		if ((j - tmp) != 1)
			ft_normal_moves(moves, j);
		j++;
	}
}

/* Check if a string is empty or contains only spaces. */
int	empty_file(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && *str && *str == ' ')
		str++;
	if (!str)
		return (1);
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}
