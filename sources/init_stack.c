/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:05:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 12:17:28 by gde-la-r         ###   ########.fr       */
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
		last = ft_last_node(*stack);
		last->next = temp;
	}
}

void	init_stack_a(t_stack **stack, char **nums)
{
	int		i;
	long	n;

	if (only_numbers(nums) == 0)
		return (ft_printf("Error"));
	i = 0;
	while (nums[i])
	{
		n = ft_atoi(nums[i++]);
		if (n > INT_MAX || n < INT_MIN)
			return (ft_error(stack));
		else if (doubles(*stack, (int)n) == 0)
			return (ft_error(stack));
		create_nodes(a, (int)n);
	}
}
