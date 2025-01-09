/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:20:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/09 20:00:34 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *s)
{
	int	print;

	if (!s)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	print = 0;
	while (s)
	{
		ft_printf("%d ", s->n);
		s = s->next;
		print++;
	}
	if (print > 0)
		ft_printf("\n");
}

void	print_index(t_stack *s)
{
	int	print;

	if (!s)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	print = 0;
	while (s)
	{
		ft_printf("%d ", s->index);
		s = s->next;
		print++;
	}
	if (print > 0)
		ft_printf("\n");
}

void	print_median(t_stack *s)
{
	int	print;

	if (!s || !s->target)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	print = 0;
	while (s)
	{
		ft_printf("%d ", s->median);
		s = s->next;
		print++;
	}
	if (print > 0)
		ft_printf("\n");
}

void	print_target(t_stack *s)
{
	int	print;

	if (!s)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	print = 0;
	while (s)
	{
		if (s->target)
			ft_printf("%d ", s->target->n);
		else
			ft_printf("NULL ");
		s = s->next;
		print++;
	}
	if (print > 0)
		ft_printf("\n");
}
