/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:07:46 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/24 21:50:02 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	gnl(t_stack **a, t_stack **b);
static int	do_ops(t_stack **a, t_stack **b, char *line);

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
	if (a == NULL)
		return (-1);
	if (!ft_sorted(a))
		gnl(&a, &b);
	if (ft_sorted(a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(&a, &b, av, ac);
	return (0);
}

static int	gnl(t_stack **a, t_stack **b)
{
	int		check;
	char	*line;

	check = 0;
	line = get_next_line(0);
	while (line)
	{
		check = do_ops(a, b, line);
		free(line);
		if (check == -1)
			return (-1);
		line = get_next_line(0);
	}
	return (0);
}

static int	do_ops(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, 0);
	else
		return (ft_printf("KO\n"));
	return (0);
}
