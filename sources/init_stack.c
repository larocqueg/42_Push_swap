/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:29:54 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/12/17 15:28:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

static long	ft_atol(char *str)
{
	long n;
	int sign;

	n = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	return (n * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last;

	if (!stack)
		return ;
	node =(t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->cheapest = 0;
	node->next = NULL;
	node->nb = n;
	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack(t_stack **a, char **av)
{
	long 	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			ft_free(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_free(a);
		if (dup_error(*a, (int)n))
			ft_free(a);
		append_node(a, (int)n);
		i++;
	}
}
