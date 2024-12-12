/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/12/09 11:03:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || av[1][0] == 0)
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_init_stack_a(&a, ++av);
	if (!sorted_stack(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (ft_stack_len(a) == 3)
			ft_sort_3(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
