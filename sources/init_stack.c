/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:05:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/04 20:28:19 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stack *stack, char **nums)
{
	int		i;
	long	n;

	i = 0;
	while(av[i])
	{
		if (!only_numbers(nums[i]))
		{
			ft_error(stack);
			return (ft_printf("Error"));
		}
		n = ft_atoi(nums[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_error(stack);
			return (ft_printf("Error"));
		}
		if (doubles(*stack, (int)n))
		{
			ft_error(stack);
			return (ft_printf("Error");
		}
		create_nodes(a, (int)n);
		i++;
	}
}
