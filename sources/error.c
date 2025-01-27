/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:35:29 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/27 17:46:37 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	a = NULL;
	return (ft_putstr_fd("Error\n", 2), -1);
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
			if (arr[i][j] == '-' || arr[i][j] == '+')
			{
				if (!(arr[i][j + 1] >= '0' && arr[i][j + 1] <= '9'))
					return (0);
			}
			else if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	doubles(t_stack *stack, int n)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (n == stack->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
