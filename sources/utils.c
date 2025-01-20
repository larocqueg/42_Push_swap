/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:03 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/20 10:33:27 by gde-la-r         ###   ########.fr       */
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

void	check_2(t_stack **stack)
{
	if ((*stack)->n > (*stack)->next->n)
		sa(stack, 1);
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

void	find_cheapest(t_stack *a)
{
	t_stack	*hold;
	t_stack	*temp;

	hold = a;
	temp = a;
	while (a)
	{
		if (a->next == NULL)
			break ;
		if (a->cost < a->next->cost && a->cost < hold->cost)
			hold = a;
		a = a->next;
	}
	a = temp;
	while (a)
	{
		if (a->index == hold->index)
			a->cheapest = 1;
		else
			a->cheapest = 0;
		a = a->next;
	}
}
