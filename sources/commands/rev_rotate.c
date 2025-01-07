/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:52:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/07 14:37:27 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, int n)
{
	rev_rotate(a);
	if (n != 0)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int n)
{
	rev_rotate(b);
	if (n != 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	rev_rotate(a);
	rev_rotate(b);
	if (n != 0)
		ft_printf("rrr\n");
}
