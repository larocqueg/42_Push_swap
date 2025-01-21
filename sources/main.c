/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:53:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/21 00:16:03 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	a = init_stack_a(&a, av, ac);
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			check_2(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	ft_printf("stack_a: ");
	print_stack(a);
	ft_printf("stack_b: ");\
	print_stack(b);
	ft_free(&a, &b, av, ac);
	return (0);
}
