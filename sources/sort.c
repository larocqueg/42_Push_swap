/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/05 19:11:20 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while(stack->next)
	{
		if (stack->n > stack->n->next)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_three(t_stack *a)
{
	if (s->n > s->next->n && s->next->n > s->next->next->n)
	{
		sa(s);
		rra(s);
	}
	else if (s->n > s->next->next->n && s->next->next->n > s->next->n)
		ra(s);
	else if (s->next->n > s->n && s->n > s->next->next->n)
		rra(s);
	else if (s->next->n > s->next->next->n && s->next->next->n > s->n)
		sa(s);
	else if (s->next->next->n > s->n && s->n > s->next->n)
	{
		sa(s);
		ra(s);
	}
}

void	ft_sort_stacks(t_stack *a, t_stack *b)
{
}
