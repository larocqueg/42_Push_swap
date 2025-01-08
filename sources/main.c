/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:53:31 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/08 15:40:10 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *s)
{
	int	print;

	if (!s)
		ft_printf("(NULL)\n");
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
	a = init_stack_a(&a, av);
	ft_printf("stack_a: ");
	print_stack(a);
	ft_printf("stack_b: ");
	print_stack(b);
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
	ft_printf("stack_b: ");
	print_stack(b);
	if (ac == 2)
	{
		ft_free(&a, av);
		free_stack(&b);
		ft_printf("All stacks where freed!\n");
		ft_printf("Av where freed!\n");
	}
	else
	{
		free_stack(&a);
		free_stack(&b);
		ft_printf("All stacks where freed!\n");
	}
	return (0);
}
