/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:50:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/10 19:28:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Set index
void	set_index(t_stack *stack)
{
	int	n;
	int	len;

	if (!stack)
		return ;
	n = 0;
	len = ft_stack_len(stack);
	while (stack)
	{
		stack->index = n++;
		if (stack->index < len / 2 || stack->index > len / 2)
		{
			stack->median = 0;
			if (stack->index < len / 2)
				stack->above_median = 0;
			else if (stack->index > len / 2)
				stack->above_median = 1;
		}
		else
		{
			stack->median = 1;
			stack->above_median = 0;
		}
		stack = stack->next;
	}
}

// Set targert
void	set_target_a(t_stack *a, t_stack *b)
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

// Find cost
void	set_cost(t_stack *stack)
{
}

// Reset index, median, above_median, target and cost
void	reset_index(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_target_a(*a, *b);
	//set_target_b(*a, *b);
	set_cost(*a);
	//set_cost(*b);
}
