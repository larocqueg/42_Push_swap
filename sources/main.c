/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:53:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/04 20:40:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		if (!av[1][0])
			return (0);
		av = ft_split(av[1], ' ');
	}
	a = init_stack(&a, av + 1);
	if (!sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
