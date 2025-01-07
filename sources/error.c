/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:35:29 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/07 14:44:50 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(t_stack *a)
{
	free(a);
	return (ft_printf("Error\n"));
}

int	only_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	doubles(t_stack **stack, int n)
{
	if (!*stack)
		return (1);
	while ((*stack)->next)
	{
		if (n == (*stack)->n)
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}
