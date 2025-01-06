/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:52:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 13:38:47 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclyde "../../inlcudes/push_swap.h"

static	void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	sa(t_stack **ai, int n)
{
	swap(*a);
	if (n != 0)
		ft_printf("sa\n");
	return ;
}

void	sb(t_stack **b, int n)
{
	swap(*b);
	if (n != 0)
		ft_printf("sb\n");
	return ;
}

void	ss(t_stack **a, t_stack **b, int n)
{
	swap(*a);
	swap(*b);
	if (n != 0)
		ft_printf("ss\n");
	return ;
}
