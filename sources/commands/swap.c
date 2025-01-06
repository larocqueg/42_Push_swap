/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:52:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 12:37:33 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
