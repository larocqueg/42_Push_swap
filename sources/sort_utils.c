/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:50:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:29 by gde-la-r         ###   ########.fr       */
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

// Set targert

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target_node;

	if (!a || !b)
		return ;
	while (a)
	{
		temp_b = b;
		target_node = NULL;
		while (temp_b)
		{
			if ((!target_node || temp_b->n > target_node->n)
				&& temp_b->n < a->n)
				target_node = temp_b;
			temp_b = temp_b->next;
		}
		if (!target_node)
			a->target = max_n(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

// Find max number
t_stack	*max_n(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
