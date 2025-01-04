/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/04 20:29:48 by gde-la-r         ###   ########.fr       */
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
	while (stack != NULL)
	{
		temp = stack->next;
		len++;
	}
	return (len);
}

int	only_numbers(char *str)
{
	while(*str)
	{
		if (str < '0' || str > '9')
			return (0);
		i++;
	}
	return (1);
}
