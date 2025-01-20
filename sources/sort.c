/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/20 12:09:46 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len);
static void	set_cheapest_to_top(t_stack **a, t_stack *cheapest);

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
	push_b_to_a(a, b);
}

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len)
{
	t_stack	*cheapest;

	while (len > 3)
	{
		reset_index(a, b);
		cheapest = return_cheapest(*a);
		if (cheapest->above_median == 0
			&& cheapest->target->above_median == 0)
			rr(a, b, 1);
		else if (cheapest->above_median == 1
			&& cheapest->target->above_median == 1)
			rrr(a, b, 1);
		set_cheapest_to_top(a, cheapest);
		set_cheapest_to_top(b, cheapest->target);
		pb(a, b, 1);
		len--;
	}
	ft_sort_three(a);
	reset_index(a, b);
}

static void	set_cheapest_to_top(t_stack **a, t_stack *cheapest)
{
	while(*a != cheapest)
	{
		if (cheapest->above_median == 0)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
