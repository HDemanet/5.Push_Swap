/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:25:34 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/08 15:40:05 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the linked list stack_a is sorted in ascending order. */
int	ft_is_stack_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next != NULL)
	{
		if ((stack_a->next->content) < (stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

/* Sorts the stack stack_a using the appropriate sorting algorithm based on the 
number of elements and stores the moves in the moves array. */
void	sort_stack(t_list *stack_a, t_list *stack_b, char moves[], int nb)
{
	int	i;

	i = 0;
	if (ft_is_stack_sorted(stack_a))
		;
	else if (nb == 1)
		;
	else if (nb == 2)
	{
		if ((stack_a)->content > (stack_a)->next->content)
			i = sa(stack_a, moves, i);
	}
	else if (nb == 3)
		i = ft_sort_three(&stack_a, moves, i);
	else if (nb == 4)
		i = ft_sort_four(&stack_a, &stack_b, moves, i);
	else if (nb == 5)
		i = ft_sort_five(&stack_a, &stack_b, moves, i);
	else
		i = ft_cost_algorithm(&stack_a, &stack_b, moves, i);
	ft_print_moves(moves, i);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

/* Initializes stacks, validates input, loads stack_a, and sorts it if valid. */
int	main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			moves[1000000];
	int				nb_elem;

	stack_b = NULL;
	nb_elem = 0;
	if (empty_file(av[1]))
		return (0);
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	nb_elem = ft_count_numbers(av);
	stack_a = ft_load_stack_from_args(av);
	if (stack_a == NULL)
		write(2, "Error\n", 6);
	else
		sort_stack(stack_a, stack_b, moves, nb_elem);
}
