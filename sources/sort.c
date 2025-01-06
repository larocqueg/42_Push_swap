/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:21:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:49 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_stack *stack)
	{
		sa(s, 1);
		rra(s);
	}
	else if ((*s)->n > (*s)->next->next->n
		&& (*s)->next->next->n > (*s)->next->n)
		ra(s, 1);
	else if ((*s)->next->n > (*s)->n && (*s)->n > (*s)->next->next->n)
		rra(s, 1);
	else if ((*s)->next->n > (*s)->next->next->n
		&& (*s)->next->next->n > (*s)->n)
		sa(s, 1);
	else if ((*s)->next->next->n > (*s)->n && (*s)->n > (*s)->next->n)
	{
		sa(s, 1);
		ra(s, 1);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
}
