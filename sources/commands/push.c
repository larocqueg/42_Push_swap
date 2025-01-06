/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:51:56 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 14:35:04 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack **dest, t_stack **origin)
{
	t_stack	*temp;

	if (!(*origin))
		return ;
	temp = *origin;
	*origin = (*origin)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_stack **a, t_stack **b, int n)
{
	push (b, a);
	if (n != 0)
		printf("pb\n");
	return ;
}

void	pb(t_stack **a, t_stack **b, int n)
{
	push(a, b);
	if (n != 0)
		printf("pa\n");
	return ;
}
