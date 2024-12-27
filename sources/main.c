/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:49:30 by gde-la-r          #+#    #+#             */
/*   Updated: 2024/12/27 13:40:11 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Declare pointers to 2 data structs(linked lists) a and b then set both to NULL;

if (ac == 1 || (ac == 2 && !av[1][0]))
	return (1);
This if is going to check if the input is invalid, neither if the number of
arguments is less then < 2 or if it is 2 and the 1st string of the argument
is empty, if so it returns 1 indicating error and do nothing more;

else if (ac == 2)
	res = ft_split[av[1], ' ');
This else if is going to split the argument av[1] in words;

then it will check if the given arguments are out of order, if so it
will check the len of the stack, if it is 2 it will do swap_a;
if it is 3 it will call the sort three function, it will;
if it is > 3 it will call sort_stacks function.

After sorting the stacks it frees the allocated memory and returns 0,
indicating success
*/

#include ".././includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_init_a(&a, av + 1);
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
