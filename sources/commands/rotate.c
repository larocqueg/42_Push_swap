/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:52:07 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/07 14:39:54 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, int n)
{
	rotate(a);
	if (n != 0)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int n)
{
	rotate(b);
	if (n != 0)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int n)
{
	rotate(a);
	rotate(b);
	if (n != 0)
		ft_printf("rr\n");
}
