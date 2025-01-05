/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/05 19:09:42 by gde-la-r         ###   ########.fr       */
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

int	only_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while(arr[i])
	{
		while(arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
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
	while(stack->next)
	{
		if (n == stack->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
