/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:49:30 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/12/16 19:49:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**res;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		res = ft_split(av[1], ' ');
	ft_init_a(&a, res + 1);
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
