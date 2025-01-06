/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:52:07 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 16:14:37 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_last(*stack);
}

void	ra(t_stack **a, int n)
{
	rotate(a);
	if (n != 0)
		ft_prinf("ra\n");
	return ;
}

void	rb(t_stack **b, int n)
{
	rotate(b)
	if (n != 0)
		ft_printf("rb\n");
	return ;
}

void	rr(t_stack **a, t_stack **b, int n)
{
	rotate(a);
	rotate(b);
	if (n != 0)
		ft_printf("rr\n");
	return ;
}
