/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:05:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/21 19:12:40 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_nodes(t_stack **stack, int n)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack)
		return ;
	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->n = n;
	temp->next = NULL;
	temp->cheapest = 0;
	if (!(*stack))
		*stack = temp;
	else
	{
		last = ft_last(*stack);
		last->next = temp;
	}
}

t_stack	*init_stack_a(t_stack **stack, char **nums, int ac)
{
	int		i;
	long	n;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	if (only_numbers(&nums[i]) == 0)
		return (ft_printf("Error\n"), NULL);
	while (nums[i])
	{
		n = ft_atolong(nums[i++]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_error(*stack);
			return (NULL);
		}
		if (doubles(*stack, (int)n) == 0)
		{
			ft_error(*stack);
			return (NULL);
		}
		create_nodes(stack, (int)n);
	}
	return (*stack);
}

void	lower_on_top(t_stack **a)
{
	t_stack	*min;

	min = min_n(*a);
	while ((*a)->n != min->n)
	{
		if (min->above_median == 0)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
