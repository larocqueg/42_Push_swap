/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/03 15:08:40 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack *s)
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

void	push_2_smallest_to_b(t_stack **a, t_stack **b)
{
	int	small;
	int	position;
	int	i;

	i = 0;
	while (i < 2)
	{
		small = find_smallest(*a);
		position = find_position(*a, small);
		while ((*a)->n <= (ft_stack_len(*a) / 2))
		{
			if (position <= (ft_stack_len(*a) / 2))
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	if ((*b)->n < (*a)->n)
		pa(b, a);
	else
	{
		pa(b, a);
		ra(a);
	}
}
