/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/06 14:47:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

size_t	ft_stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*temp;

	if (!stack && !stack->next)
		return (0);
	temp = stack;
	len = 0;
	while (stack != NULL)
	{
		temp = stack->next;
		len++;
	}
	return (len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
