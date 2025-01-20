/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:25:37 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/20 20:25:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*target_node;

	if (!a || !b)
		return ;
	while (b)
	{
		temp_a = a;
		target_node = NULL;
		while (temp_a)
		{
			if ((!target_node || temp_a->n < target_node->n)
				&& temp_a->n > b->n)
				target_node = temp_a;
			temp_a = temp_a->next;
		}
		if (!target_node)
			b->target = min_n(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

t_stack	*min_n(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->n < min->n)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*return_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
