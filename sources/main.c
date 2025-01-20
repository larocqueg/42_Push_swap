/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:53:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/20 09:46:08 by gde-la-r         ###   ########.fr       */
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

	// print
	ft_printf("stack_a: ");
	print_stack(a);
	ft_printf("stack_b: ");
	print_stack(b);
	// print end
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			check_2(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}

	// print
	// Stack_a
	ft_printf("stack_a->n: ");
	print_stack(a);
	ft_printf("stack_a->cost: ");
	print_cost(a);
	ft_printf("stack_a->cheapest: ");
	print_cheap(a);
	ft_printf("stack_a->target: ");
	print_target(a);
	// Stack_b
	ft_printf("stack_b->n: ");
	print_stack(b);
	// print end
	if (ac == 2)
	{
		ft_free(&a, av);
		free_stack(&b);
	}
	else
	{
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
