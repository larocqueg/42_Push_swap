/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:53:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/07 14:17:16 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		mem;
	t_stack	*a;
	t_stack	*b;

	mem = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		mem = 1;
	}
	a = init_stack_a(&a, av + 1);
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, 0);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort(&a, &b);
	}
	ft_free(&a, av + 1);
	return (0);
}
