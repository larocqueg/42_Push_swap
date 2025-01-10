/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/10 19:24:34 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_three(t_stack **s)
{
	if ((*s)->n > (*s)->next->n && (*s)->next->n > (*s)->next->next->n)
	{
		sa(s, 1);
		rra(s, 1);
	}
	else if ((*s)->n > (*s)->next->next->n
		&& (*s)->next->next->n > (*s)->next->n)
		ra(s, 1);
	else if ((*s)->next->n > (*s)->n && (*s)->n > (*s)->next->next->n)
		rra(s, 1);
	else if ((*s)->n > (*s)->next->n && (*s)->n < (*s)->next->next->n)
		sa(s, 1);
	else if ((*s)->next->next->n > (*s)->n && (*s)->n > (*s)->next->n)
		sa(s, 1);
	else if ((*s)->next->n > (*s)->next->next->n)
	{
		sa(s, 1);
		ra(s, 1);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	size_t	len;
	int		count;

	if (!a || !*a)
		return ;
	count = 2;
	len = ft_stack_len(*a);
	while (len > 3 && count > 0)
	{
		pb(a, b, 1);
		count--;
		len--;
	}
	reset_index(a, b);
	/*
	while (len > 3)
	{
		reset_index(a, b);
		if ()
		{
			pb(a, b, 1);
			len--;
		}
		else if ((*a)->target->above_median == 1)
			rrb(b, 1);
		else if ((*a)->target->above_median == 0)
			rb(b, 1);
	}*/
}
