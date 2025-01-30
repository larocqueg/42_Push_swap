/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:35:29 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/30 14:45:45 by gde-la-r         ###   ########.fr       */
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

static int	only_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
			i++;
		if (str[i] != '0' && str[i])
			return (0);
		i++;
	}
	return (1);
}

static int	valid_size(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-' && ft_strlen(arr[i]) > 20
				&& only_zero(arr[i]) == 0)
				return (0);
			else if (j == 0 && ft_strlen(arr[i]) > 19 && only_zero(arr[i]) == 0)
				return (0);
			else
				break ;
		}
		i++;
	}
	return (1);
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
				else if (j > 1 && arr[i][j - 1] >= 0 && arr[i][j -1] <= 9)
					return (0);
			}
			else if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	if (valid_size(arr) == 0)
		return (0);
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
