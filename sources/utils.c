/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/22 15:11:09 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

size_t	ft_stack_len(t_stack *stack)
{
	size_t	len;

	if (!stack && !stack->next)
		return (0);
	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*ft_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

long	ft_atolong(const char *str)
{
	int		i;
	int		sign;
	long	num;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((sign * num));
}

static int	ret_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else if (n1 < n2)
		return (n2);
	else
		return (n1);
}

t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

	cheapest = NULL;
	temp = *stack;
	while (temp)
	{
		temp->push_cost = 0;
		if (temp->above_median == temp->target->above_median)
			temp->push_cost = ret_max(temp->cost, temp->target->cost);
		else
			temp->push_cost = temp->cost + temp->target->cost;
		if (!cheapest)
			cheapest = temp;
		else if (temp->push_cost < cheapest->push_cost)
			cheapest = temp;
		temp = temp->next;
	}
	cheapest->cheapest = 1;
	return (cheapest);
}
