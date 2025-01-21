/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/21 18:53:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len);
static void	sort_stacks_utils_utils(t_stack **a, t_stack **b);

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
		len--;
		count--;
	}
	sort_stacks_utils(a, b, len);
	sort_stacks_utils_utils(a, b);
	reset_index(a, b);
	lower_on_top(a);
}

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len)
{
	t_stack	*cheapest;

	while ((*a)->next->next->next)
	{
		reset_index(a, b);
		cheapest = return_cheapest(*a);
		while ((*a != cheapest && *b != cheapest->target)
			&& cheapest->above_median == cheapest->target->above_median)
		{
			if (cheapest->above_median == 0
				&& cheapest->target->above_median == 0)
				rr(a, b, 1);
			else if (cheapest->above_median == 1
				&& cheapest->target->above_median == 1)
				rrr(a, b, 1);
		}
		set_cheapest_to_top(a, cheapest, 1);
		set_cheapest_to_top(b, cheapest->target, 2);
		pb(a, b, 1);
		len--;
	}
	ft_sort_three(a);
	reset_index(a, b);
}

static void	sort_stacks_utils_utils(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		reset_index(a, b);
		cheapest = return_cheapest(*b);
		while ((*b != cheapest && *a != cheapest->target)
			&& cheapest->above_median == cheapest->target->above_median)
		{
			if (cheapest->above_median == 0
				&& cheapest->target->above_median == 0)
				rr(a, b, 1);
			else if (cheapest->above_median == 1
				&& cheapest->target->above_median == 1)
				rrr(a, b, 1);
		}
		set_cheapest_to_top(b, cheapest, 2);
		set_cheapest_to_top(a, cheapest->target, 1);
		pa(a, b, 1);
	}
}
