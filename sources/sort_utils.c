/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:50:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/08 21:49:28 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Set index
void	set_index(t_stack *stack)
{
	int	n;

	if (!stack)
		return ;
	n = 0;
	while (stack)
	{
		stack->index = n++;
		stack = stack->next;
	}
}

// Set cost

// Find cheapest

// Set median
void	set_median(t_stack *stack)
{
	int	len;

	if (!stack)
		return ;
	len = ft_stack_len(stack);
	while (stack && stack->index < (len / 2))
	{
		stack->median = 0;
		stack = stack->next;
	}
	if (stack)
	{
		stack->median = 1;
		stack = stack->next;
	}
	while (stack)
	{
		stack->median = 0;
		stack = stack->next;
	}
}

// above_median ?
